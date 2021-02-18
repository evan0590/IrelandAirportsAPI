#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/rds/RDSClient.h>
#include <aws/rds/model/CreateDBInstanceRequest.h>
#include <aws/rds/model/CreateDBInstanceResult.h>
#include <iostream>

void StartInstance(const Aws::String &db_name, const Aws::String &db_instance_identifier, const Aws::String &master_user_password, const Aws::String &sg_id)
{
    Aws::RDS::RDSClient rds;

    Aws::RDS::Model::CreateDBInstanceRequest create_request;
    create_request.SetDBName(db_name);
    create_request.SetDBInstanceIdentifier(db_instance_identifier);
    create_request.SetDBInstanceClass("db.t2.micro");
    create_request.SetEngine("postgres");
    create_request.SetMasterUsername("postgres");
    create_request.SetMasterUserPassword(master_user_password);
    create_request.SetAllocatedStorage(20);
    create_request.SetMultiAZ(false);
    create_request.AddVpcSecurityGroupIds(sg_id);
    create_request.SetAvailabilityZone("eu-west-1b");

    auto run_outcome = rds.CreateDBInstance(create_request);
    if (!run_outcome.IsSuccess())
    {
        std::cout << "Failed to start rds instance " << db_instance_identifier << " :" << run_outcome.GetError().GetMessage() << std::endl;
        return;
    }

    std::cout << "Successfully started rds instance " << db_instance_identifier << std::endl;
}

/**
 * Creates an rds instance based on command line input
 */
int main(int argc, char **argv)
{
    if (argc != 5)
    {
        std::cout << "Usage: create_instance <db_name> <db_instance_identifier> <instance_class> <master_user_password> <sg_id>"
                  << std::endl;
        return 1;
    }

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        /*
        * The user must supply a first parameter on the command line to be used as the db_name string.
        * example db_name string: "airports_database"
        */
        Aws::String db_name = argv[1];

        /*
        * The user must supply a first parameter on the command line to be used as the db_instance_identifier string.
        * example db_instance_identifier string: "test"
        */
        Aws::String db_instance_identifier = argv[2];

        /*
        * The user must supply a first parameter on the command line to be used as the master_user_password string.
        * example master_user_password string: "password1"
        */
        Aws::String master_user_password = argv[3];

        /*
        * The user must supply a first parameter on the command line to be used as the sg_id string.
        * example sg_id string: "sg-70987as09879087d3"
        */
        Aws::String sg_id = argv[4];

        StartInstance(db_name, db_instance_identifier, master_user_password, sg_id);
    }

    Aws::ShutdownAPI(options);
    return 0;
}