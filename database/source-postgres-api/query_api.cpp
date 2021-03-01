#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <cpr/cpr.h>
#include <json.hpp>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    const char *buildroute;
    const char *apikey;
    const char *deparriata;
    const char *airportiata;

    /*
     * The user must supply a first parameter on the command line to be used as the buildroute string.
     * example route string: "/home/ubuntu/IrelandAirportsAPI/build/"
     */
    buildroute = argv[1];
    /*
     * The user must supply a second parameter on the command line to be used as the apikey string.
     * example apikey string: "1a2s3d21g5r3a3f15wfa3"
     */
    apikey = argv[2];
    /*
     * The user must supply a third parameter on the command line to be used as the deparriata string.
     * deparriata string may be either: "dep_iata" or "arr_iata"
     */
    deparriata = argv[3];
    /*
     * The user must supply a fourth parameter on the command line to be used as the airportiata string.
     * example airportiata string: "SNN"
     */
    airportiata = argv[4];

    /* make request to the api with the given parameters */
    cpr::Response response = cpr::Get(cpr::Url{"http://api.aviationstack.com/v1/flights"},
                                      cpr::Parameters{{"access_key", apikey},
                                                      {deparriata, airportiata}});
    auto json = nlohmann::json::parse(response.text);

    /* convert char array parameters to strings for naming json files */
    std::string buildroute_s = buildroute;
    std::string deparriata_s = deparriata;
    std::string airportiata_s = airportiata;

    /* create a json directory if it doesn't already exist */
    fs::create_directory(buildroute_s + "json/");

    /* create a json file to store the queried information */
    std::ofstream file;
    file.open(buildroute_s + "json/" + deparriata_s + "_" + airportiata_s + ".json");
    file << json;
    file.close();

    return 0;
}