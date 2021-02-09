#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/rds/RDSClient.h>
#include <aws/rds/model/CreateDBInstanceRequest.h>
#include <aws/rds/model/CreateDBInstanceResult.h>
#include <iostream>

void StartInstance(const Aws::String &dbName, const Aws::String &dbInstanceIdentifier, const Aws::String &masterUserPassword, const Aws::String &sg_id)
{

    Aws::RDS::RDSClient rds;

    Aws::RDS::Model::CreateDBInstanceRequest create_request;
    create_request.SetDBName(dbName);
    create_request.SetDBInstanceIdentifier(dbInstanceIdentifier);
    create_request.SetDBInstanceClass("db.t2.micro");
    create_request.SetEngine("postgres");
    create_request.SetMasterUsername("postgres");
    create_request.SetMasterUserPassword(masterUserPassword);
    create_request.SetAllocatedStorage(20);
    create_request.SetMultiAZ(false);
    create_request.AddVpcSecurityGroupIds(sg_id);
    create_request.SetAvailabilityZone("eu-west-1b");

    auto run_outcome = rds.CreateDBInstance(create_request);
    if (!run_outcome.IsSuccess())
    {
        std::cout << "Failed to start rds instance " << dbInstanceIdentifier << " :" << run_outcome.GetError().GetMessage() << std::endl;
        return;
    }

    std::cout << "Successfully started rds instance " << dbInstanceIdentifier << std::endl;
}

/**
 * Creates an rds instance based on command line input
 */
int main(int argc, char **argv)
{
    if (argc != 5)
    {
        std::cout << "Usage: create_instance <dbName> <dbInstanceIdentifier> <instanceClass> <masterUserPassword> <sg_id>"
                  << std::endl;
        return 1;
    }

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        Aws::String dbName = argv[1];
        Aws::String dbInstanceIdentifier = argv[2];
        Aws::String masterUserPassword = argv[3];
        Aws::String sg_id = argv[4];
        StartInstance(dbName, dbInstanceIdentifier, masterUserPassword, sg_id);
    }
    Aws::ShutdownAPI(options);
    return 0;
}