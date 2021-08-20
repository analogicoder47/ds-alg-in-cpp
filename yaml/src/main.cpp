#include <iostream>
#include <vector>

#include "../include/session_info.h"

int main(int argc, char** argv)
{
    YAML::Node config = YAML::LoadFile("../session_info.yaml");

    ServerInfo svrInfo = config["server_info"].as<ServerInfo>();
    std::cout << "server ip: "          << svrInfo.ip         << std::endl;
    std::cout << "server port: "        << svrInfo.port       << std::endl;
    std::cout << "server backlog: "     << svrInfo.backlog    << std::endl;
    std::cout << "server sender_comp: " << svrInfo.snder_comp << std::endl;

    std::cout << "====================================================" << std::endl;

    std::vector<BrokerInfo> brokerVect = config["broker_info"].as<std::vector<BrokerInfo>>();
    for (std::vector<BrokerInfo>::iterator iter = brokerVect.begin(); iter != brokerVect.end(); iter++) {
        std::cout << "broker ip: "             << iter->ip             << std::endl;
        std::cout << "broker port: "           << iter->port           << std::endl;
        std::cout << "broker target company: " << iter->target_comp    << std::endl;
        std::cout << "broker expected seqno: " << iter->expected_seqno << std::endl;
        std::cout << "broker passwd: "         << iter->passwd         << std::endl;
    }

    return 0;
}