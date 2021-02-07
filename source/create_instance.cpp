#include <aws/core/Aws.h>
#include <aws/ec2/EC2Client.h>
#include <aws/ec2/model/CreateTagsRequest.h>
#include <aws/ec2/model/RunInstancesRequest.h>
#include <aws/ec2/model/RunInstancesResponse.h>
#include <iostream>

void StartInstance(const Aws::String &instanceName, const Aws::String &ami_id, const Aws::String &sg_id, const Aws::String &key_name)
{

    Aws::EC2::EC2Client ec2;

    Aws::EC2::Model::RunInstancesRequest run_request;
    run_request.SetImageId(ami_id);
    run_request.SetInstanceType(Aws::EC2::Model::InstanceType::t2_micro);
    run_request.AddSecurityGroupIds(sg_id);
    run_request.SetKeyName(key_name);
    run_request.SetMinCount(1);
    run_request.SetMaxCount(1);

    auto run_outcome = ec2.RunInstances(run_request);
    if (!run_outcome.IsSuccess())
    {
        std::cout << "Failed to start ec2 instance " << instanceName << " based on ami " << ami_id << ":" << run_outcome.GetError().GetMessage() << std::endl;
        return;
    }

    const auto &instances = run_outcome.GetResult().GetInstances();
    if (instances.size() == 0)
    {
        std::cout << "Failed to start ec2 instance " << instanceName << " based on ami " << ami_id << ":" << run_outcome.GetError().GetMessage() << std::endl;
        return;
    }

    auto instance_id = instances[0].GetInstanceId();

    Aws::EC2::Model::Tag name_tag;
    name_tag.SetKey("Name");
    name_tag.SetValue(instanceName);

    Aws::EC2::Model::CreateTagsRequest create_request;
    create_request.AddResources(instance_id);
    create_request.AddTags(name_tag);

    auto create_outcome = ec2.CreateTags(create_request);
    if (!create_outcome.IsSuccess())
    {
        std::cout << "Failed to tag ec2 instance " << instance_id << " with name " << instanceName << ":" << create_outcome.GetError().GetMessage() << std::endl;
        return;
    }

    std::cout << "Successfully started ec2 instance " << instanceName << " based on ami " << ami_id << std::endl;
}

/**
 * Creates an ec2 instance based on command line input
 */
int main(int argc, char **argv)
{
    if (argc != 5)
    {
        std::cout << "Usage: create_instance <instance_name> <ami_image_id> <security_group_id> <key_name>"
                  << std::endl;
        return 1;
    }

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        Aws::String instanceName = argv[1];
        Aws::String ami_id = argv[2];
        Aws::String sg_id = argv[3];
        Aws::String key_name = argv[4];
        StartInstance(instanceName, ami_id, sg_id, key_name);
    }
    Aws::ShutdownAPI(options);
    return 0;
}
