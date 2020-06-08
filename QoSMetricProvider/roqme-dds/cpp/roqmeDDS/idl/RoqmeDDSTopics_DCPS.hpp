#ifndef ISOCPP2_RoqmeDDSTopics_H
#define ISOCPP2_RoqmeDDSTopics_H

#include "dds/dds.hpp"

#include "RoqmeDDSTopics.h"
#include "RoqmeDDSTopicsSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeIntContext>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeIntContext";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"intseq\"><Sequence><LongLong/>",
"</Sequence></TypeDef><Struct name=\"RoqmeIntContext\"><Member name=\"name\"><String/></Member><Member name=\"value\">",
"<Type name=\"intseq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(284);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeIntContext__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeIntContext__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeIntContext>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeIntContext>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeIntContext)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeUIntContext>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeUIntContext";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"uintseq\"><Sequence><ULongLong/>",
"</Sequence></TypeDef><Struct name=\"RoqmeUIntContext\"><Member name=\"name\"><String/></Member><Member name=\"value\">",
"<Type name=\"uintseq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(288);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeUIntContext__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeUIntContext__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeUIntContext>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeUIntContext>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeUIntContext)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeDoubleContext>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeDoubleContext";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"doubleseq\"><Sequence><Double/>",
"</Sequence></TypeDef><Struct name=\"RoqmeDoubleContext\"><Member name=\"name\"><String/></Member><Member name=\"value\">",
"<Type name=\"doubleseq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(291);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeDoubleContext__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeDoubleContext__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeDoubleContext>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeDoubleContext>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeDoubleContext)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeBoolContext>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeBoolContext";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"boolseq\"><Sequence><Boolean/>",
"</Sequence></TypeDef><Struct name=\"RoqmeBoolContext\"><Member name=\"name\"><String/></Member><Member name=\"value\">",
"<Type name=\"boolseq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(286);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeBoolContext__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeBoolContext__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeBoolContext>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeBoolContext>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeBoolContext)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeEventContext>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeEventContext";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"eventseq\"><Sequence><String/>",
"</Sequence></TypeDef><Struct name=\"RoqmeEventContext\"><Member name=\"name\"><String/></Member><Member name=\"value\">",
"<Type name=\"eventseq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(288);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeEventContext__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeEventContext__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeEventContext>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeEventContext>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeEventContext)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeEnumContext>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeEnumContext";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"enumseq\"><Sequence><String/>",
"</Sequence></TypeDef><Struct name=\"RoqmeEnumContext\"><Member name=\"name\"><String/></Member><Member name=\"value\">",
"<Type name=\"enumseq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(285);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeEnumContext__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeEnumContext__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeEnumContext>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeEnumContext>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeEnumContext)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeObservation>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeObservation";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><Struct name=\"RoqmeObservation\"><Member name=\"name\">",
"<String/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(163);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeObservation__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeObservation__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeObservation>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeObservation>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeObservation)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeEstimate>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "name";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeEstimate";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><Struct name=\"RoqmeEstimate\"><Member name=\"name\">",
"<String/></Member><Member name=\"value\"><Double/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(201);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeEstimate__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeEstimate__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeEstimate>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeEstimate>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeEstimate)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<RoqmeDDSTopics::RoqmeRanking>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "metricName";
    }

    static const char *getTypeName()
    {
        return "RoqmeDDSTopics::RoqmeRanking";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"RoqmeDDSTopics\"><TypeDef name=\"id_seq\"><Sequence><String/>",
"</Sequence></TypeDef><TypeDef name=\"value_seq\"><Sequence><Double/></Sequence></TypeDef><Struct name=\"RoqmeRanking\">",
"<Member name=\"metricName\"><String/></Member><Member name=\"ids\"><Type name=\"id_seq\"/></Member><Member name=\"values\">",
"<Type name=\"value_seq\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(410);
        for (int i = 0; i < 4; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __RoqmeDDSTopics_RoqmeRanking__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __RoqmeDDSTopics_RoqmeRanking__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<RoqmeDDSTopics::RoqmeRanking>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<RoqmeDDSTopics::RoqmeRanking>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(RoqmeDDSTopics::RoqmeRanking)

#endif /* ISOCPP2_RoqmeDDSTopics_H */
