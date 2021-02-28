#include <iostream>
#include <fstream>
#include <string>
#include <cpr/cpr.h>
#include <json.hpp>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    const char *apikey;
    const char *deparriata;
    const char *airportiata;

    /*
     * The user must supply a first parameter on the command line to be used as the apikey string.
     * example apikey string: "1a2s3d21g5r3a3f15wfa3"
     */
    apikey = argv[1];
    /*
     * The user must supply a second parameter on the command line to be used as the deparriata string.
     * deparriata string may be either: "dep_iata" or "arr_iata"
     */
    deparriata = argv[2];
    /*
     * The user must supply a third parameter on the command line to be used as the airportiata string.
     * example airportiata string: "SNN"
     */
    airportiata = argv[3];

    /* make request to the api with the given parameters */
    cpr::Response response = cpr::Get(cpr::Url{"http://api.aviationstack.com/v1/flights"},
                                      cpr::Parameters{{"access_key", apikey},
                                                      {deparriata, airportiata}});
    auto json = nlohmann::json::parse(response.text);

    /* convert char array parameters to strings for naming json files */
    std::string deparriata_s = deparriata;
    std::string airportiata_s = airportiata;
    std::ofstream file;

    /* create a json directory if it doesn't already exist */
    fs::create_directory("./json/");

    /* create a json file to store the queried information */
    file.open("./json/" + deparriata_s + "_" + airportiata_s + ".json");
    file << json;
    file.close();

    return 0;
}