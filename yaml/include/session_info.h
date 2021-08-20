#include <string>
#include <yaml.h>

struct ServerInfo {
    int          port;
    int          backlog;
    std::string  ip;
    std::string  snder_comp;
};

struct BrokerInfo {
    int          port;
    int          expected_seqno;
    int          passwd;
    std::string  ip;
    std::string  target_comp;
};

namespace YAML {
    template<> struct convert<ServerInfo> {
        static Node encode(const ServerInfo&);
        static bool decode(const Node&, ServerInfo&);
    };

    template<> struct convert<BrokerInfo> {
        static Node encode(const BrokerInfo&);
        static bool decode(const Node&, BrokerInfo&);
    };    
}