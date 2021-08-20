#include "../include/session_info.h"

YAML::Node YAML::convert<ServerInfo>::encode(const ServerInfo &rhs) {
    Node node;

    node.push_back(rhs.port);
    node.push_back(rhs.backlog);
    node.push_back(rhs.ip);
    node.push_back(rhs.snder_comp);

    return node;
}

bool YAML::convert<ServerInfo>::decode(const Node &node, ServerInfo &rhs) {
    rhs.port       = node["port"].as<int>();
    rhs.backlog    = node["backlog"].as<int>();
    rhs.ip         = node["ip"].as<std::string>();
    rhs.snder_comp = node["sender_company"].as<std::string>();

    return true;
}

YAML::Node YAML::convert<BrokerInfo>::encode(const BrokerInfo &rhs) {
    Node node;

    node.push_back(rhs.port);
    node.push_back(rhs.expected_seqno);
    node.push_back(rhs.ip);
    node.push_back(rhs.target_comp);
    node.push_back(rhs.passwd);

    return node;
}

bool YAML::convert<BrokerInfo>::decode(const Node &node, BrokerInfo &rhs) {
    rhs.port           = node["port"].as<int>();
    rhs.expected_seqno = node["expected_seqno"].as<int>();
    rhs.passwd         = node["passwd"].as<int>();
    rhs.ip             = node["ip"].as<std::string>();
    rhs.target_comp    = node["target_company"].as<std::string>();

    return true;
}