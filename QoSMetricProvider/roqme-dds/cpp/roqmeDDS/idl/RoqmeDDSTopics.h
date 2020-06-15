#ifndef _ROQMEDDSTOPICS_H_
#define _ROQMEDDSTOPICS_H_

#include <dds/core/ddscore.hpp>

namespace RoqmeDDSTopics
{
    typedef std::vector< int64_t > intseq;

    class RoqmeIntContext OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        RoqmeDDSTopics::intseq value_;

    public:
        RoqmeIntContext() {}

        explicit RoqmeIntContext(
            const std::string& name,
            const RoqmeDDSTopics::intseq& value) : 
                name_(name),
                value_(value) {}

        RoqmeIntContext(const RoqmeIntContext &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeIntContext(RoqmeIntContext &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeIntContext& operator=(RoqmeIntContext &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeIntContext& operator=(const RoqmeIntContext &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeIntContext& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeIntContext& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        const RoqmeDDSTopics::intseq& value() const { return this->value_; }
        RoqmeDDSTopics::intseq& value() { return this->value_; }
        void value(const RoqmeDDSTopics::intseq& _val_) { this->value_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void value(RoqmeDDSTopics::intseq&& _val_) { this->value_ = _val_; }
#endif
    };

    typedef std::vector< uint64_t > uintseq;

    class RoqmeUIntContext OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        RoqmeDDSTopics::uintseq value_;

    public:
        RoqmeUIntContext() {}

        explicit RoqmeUIntContext(
            const std::string& name,
            const RoqmeDDSTopics::uintseq& value) : 
                name_(name),
                value_(value) {}

        RoqmeUIntContext(const RoqmeUIntContext &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeUIntContext(RoqmeUIntContext &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeUIntContext& operator=(RoqmeUIntContext &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeUIntContext& operator=(const RoqmeUIntContext &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeUIntContext& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeUIntContext& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        const RoqmeDDSTopics::uintseq& value() const { return this->value_; }
        RoqmeDDSTopics::uintseq& value() { return this->value_; }
        void value(const RoqmeDDSTopics::uintseq& _val_) { this->value_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void value(RoqmeDDSTopics::uintseq&& _val_) { this->value_ = _val_; }
#endif
    };

    typedef std::vector< double > doubleseq;

    class RoqmeDoubleContext OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        RoqmeDDSTopics::doubleseq value_;

    public:
        RoqmeDoubleContext() {}

        explicit RoqmeDoubleContext(
            const std::string& name,
            const RoqmeDDSTopics::doubleseq& value) : 
                name_(name),
                value_(value) {}

        RoqmeDoubleContext(const RoqmeDoubleContext &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeDoubleContext(RoqmeDoubleContext &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeDoubleContext& operator=(RoqmeDoubleContext &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeDoubleContext& operator=(const RoqmeDoubleContext &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeDoubleContext& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeDoubleContext& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        const RoqmeDDSTopics::doubleseq& value() const { return this->value_; }
        RoqmeDDSTopics::doubleseq& value() { return this->value_; }
        void value(const RoqmeDDSTopics::doubleseq& _val_) { this->value_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void value(RoqmeDDSTopics::doubleseq&& _val_) { this->value_ = _val_; }
#endif
    };

    typedef std::vector< bool > boolseq;

    class RoqmeBoolContext OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        RoqmeDDSTopics::boolseq value_;

    public:
        RoqmeBoolContext() {}

        explicit RoqmeBoolContext(
            const std::string& name,
            const RoqmeDDSTopics::boolseq& value) : 
                name_(name),
                value_(value) {}

        RoqmeBoolContext(const RoqmeBoolContext &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeBoolContext(RoqmeBoolContext &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeBoolContext& operator=(RoqmeBoolContext &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeBoolContext& operator=(const RoqmeBoolContext &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeBoolContext& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeBoolContext& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        const RoqmeDDSTopics::boolseq& value() const { return this->value_; }
        RoqmeDDSTopics::boolseq& value() { return this->value_; }
        void value(const RoqmeDDSTopics::boolseq& _val_) { this->value_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void value(RoqmeDDSTopics::boolseq&& _val_) { this->value_ = _val_; }
#endif
    };

    typedef std::vector< std::string > eventseq;

    class RoqmeEventContext OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        RoqmeDDSTopics::eventseq value_;

    public:
        RoqmeEventContext() {}

        explicit RoqmeEventContext(
            const std::string& name,
            const RoqmeDDSTopics::eventseq& value) : 
                name_(name),
                value_(value) {}

        RoqmeEventContext(const RoqmeEventContext &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeEventContext(RoqmeEventContext &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeEventContext& operator=(RoqmeEventContext &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeEventContext& operator=(const RoqmeEventContext &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeEventContext& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeEventContext& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        const RoqmeDDSTopics::eventseq& value() const { return this->value_; }
        RoqmeDDSTopics::eventseq& value() { return this->value_; }
        void value(const RoqmeDDSTopics::eventseq& _val_) { this->value_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void value(RoqmeDDSTopics::eventseq&& _val_) { this->value_ = _val_; }
#endif
    };

    typedef std::vector< std::string > enumseq;

    class RoqmeEnumContext OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        RoqmeDDSTopics::enumseq value_;

    public:
        RoqmeEnumContext() {}

        explicit RoqmeEnumContext(
            const std::string& name,
            const RoqmeDDSTopics::enumseq& value) : 
                name_(name),
                value_(value) {}

        RoqmeEnumContext(const RoqmeEnumContext &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeEnumContext(RoqmeEnumContext &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeEnumContext& operator=(RoqmeEnumContext &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeEnumContext& operator=(const RoqmeEnumContext &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeEnumContext& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeEnumContext& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        const RoqmeDDSTopics::enumseq& value() const { return this->value_; }
        RoqmeDDSTopics::enumseq& value() { return this->value_; }
        void value(const RoqmeDDSTopics::enumseq& _val_) { this->value_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void value(RoqmeDDSTopics::enumseq&& _val_) { this->value_ = _val_; }
#endif
    };

    class RoqmeObservation OSPL_DDS_FINAL
    {
    public:
        std::string name_;

    public:
        RoqmeObservation() {}

        explicit RoqmeObservation(
            const std::string& name) : 
                name_(name) {}

        RoqmeObservation(const RoqmeObservation &_other) : 
                name_(_other.name_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeObservation(RoqmeObservation &&_other) : 
                name_(::std::move(_other.name_)) {}

        RoqmeObservation& operator=(RoqmeObservation &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
            }
            return *this;
        }
#endif

        RoqmeObservation& operator=(const RoqmeObservation &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
            }
            return *this;
        }

        bool operator==(const RoqmeObservation& _other) const
        {
            return name_ == _other.name_;
        }

        bool operator!=(const RoqmeObservation& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
    };

    class RoqmeEstimate OSPL_DDS_FINAL
    {
    public:
        std::string name_;
        double value_;

    public:
        RoqmeEstimate() :
                value_(0.0) {}

        explicit RoqmeEstimate(
            const std::string& name,
            double value) : 
                name_(name),
                value_(value) {}

        RoqmeEstimate(const RoqmeEstimate &_other) : 
                name_(_other.name_),
                value_(_other.value_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeEstimate(RoqmeEstimate &&_other) : 
                name_(::std::move(_other.name_)),
                value_(::std::move(_other.value_)) {}

        RoqmeEstimate& operator=(RoqmeEstimate &&_other)
        {
            if (this != &_other) {
                name_ = ::std::move(_other.name_);
                value_ = ::std::move(_other.value_);
            }
            return *this;
        }
#endif

        RoqmeEstimate& operator=(const RoqmeEstimate &_other)
        {
            if (this != &_other) {
                name_ = _other.name_;
                value_ = _other.value_;
            }
            return *this;
        }

        bool operator==(const RoqmeEstimate& _other) const
        {
            return name_ == _other.name_ &&
                value_ == _other.value_;
        }

        bool operator!=(const RoqmeEstimate& _other) const
        {
            return !(*this == _other);
        }

        const std::string& name() const { return this->name_; }
        std::string& name() { return this->name_; }
        void name(const std::string& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(std::string&& _val_) { this->name_ = _val_; }
#endif
        double value() const { return this->value_; }
        double& value() { return this->value_; }
        void value(double _val_) { this->value_ = _val_; }
    };

    typedef std::vector< std::string > id_seq;

    typedef std::vector< double > value_seq;

    class RoqmeRanking OSPL_DDS_FINAL
    {
    public:
        std::string metricName_;
        RoqmeDDSTopics::id_seq ids_;
        RoqmeDDSTopics::value_seq values_;

    public:
        RoqmeRanking() {}

        explicit RoqmeRanking(
            const std::string& metricName,
            const RoqmeDDSTopics::id_seq& ids,
            const RoqmeDDSTopics::value_seq& values) : 
                metricName_(metricName),
                ids_(ids),
                values_(values) {}

        RoqmeRanking(const RoqmeRanking &_other) : 
                metricName_(_other.metricName_),
                ids_(_other.ids_),
                values_(_other.values_) {}

#ifdef OSPL_DDS_CXX11
        RoqmeRanking(RoqmeRanking &&_other) : 
                metricName_(::std::move(_other.metricName_)),
                ids_(::std::move(_other.ids_)),
                values_(::std::move(_other.values_)) {}

        RoqmeRanking& operator=(RoqmeRanking &&_other)
        {
            if (this != &_other) {
                metricName_ = ::std::move(_other.metricName_);
                ids_ = ::std::move(_other.ids_);
                values_ = ::std::move(_other.values_);
            }
            return *this;
        }
#endif

        RoqmeRanking& operator=(const RoqmeRanking &_other)
        {
            if (this != &_other) {
                metricName_ = _other.metricName_;
                ids_ = _other.ids_;
                values_ = _other.values_;
            }
            return *this;
        }

        bool operator==(const RoqmeRanking& _other) const
        {
            return metricName_ == _other.metricName_ &&
                ids_ == _other.ids_ &&
                values_ == _other.values_;
        }

        bool operator!=(const RoqmeRanking& _other) const
        {
            return !(*this == _other);
        }

        const std::string& metricName() const { return this->metricName_; }
        std::string& metricName() { return this->metricName_; }
        void metricName(const std::string& _val_) { this->metricName_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void metricName(std::string&& _val_) { this->metricName_ = _val_; }
#endif
        const RoqmeDDSTopics::id_seq& ids() const { return this->ids_; }
        RoqmeDDSTopics::id_seq& ids() { return this->ids_; }
        void ids(const RoqmeDDSTopics::id_seq& _val_) { this->ids_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void ids(RoqmeDDSTopics::id_seq&& _val_) { this->ids_ = _val_; }
#endif
        const RoqmeDDSTopics::value_seq& values() const { return this->values_; }
        RoqmeDDSTopics::value_seq& values() { return this->values_; }
        void values(const RoqmeDDSTopics::value_seq& _val_) { this->values_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void values(RoqmeDDSTopics::value_seq&& _val_) { this->values_ = _val_; }
#endif
    };

}

#endif /* _ROQMEDDSTOPICS_H_ */
