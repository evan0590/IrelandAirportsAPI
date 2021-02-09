#include <iostream>
#include <iomanip>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;

// TODO implement the sql
int main()
{

    std::ifstream file(<insert_file_name_here>);
    json j = json::parse(file);
    json parsed = j["data"];

    std::cout << std::setw(4) << j["data"][0]["airline"]["name"] << '\n';

    for (int i = 0; i < j.size(); i++)
    {
        std::cout << parsed[i]["flight_date"] << '\n';
        std::cout << parsed[i]["airline"]["name"] << '\n';
        std::cout << parsed[i]["flight"]["iata"] << '\n';
        std::cout << parsed[i]["departure"]["airport"] << '\n';
        std::cout << parsed[i]["departure"]["scheduled"] << '\n';
        std::cout << parsed[i]["arrival"]["airport"] << '\n';
        std::cout << parsed[i]["arrival"]["scheduled"] << '\n';
        std::cout << " " << '\n';
    }
}