#include "RoqmeDDSTopics_DCPS.hpp"

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__RoqmeDDSTopics_intseq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::intseq *from,
    _RoqmeDDSTopics_intseq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_longlong *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_longlong *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1598 */
        if(length0 > 0)
        {
            const c_longlong *buf0;
            buf0 = reinterpret_cast<const c_longlong *>(&((*from)[0]));
            memcpy (dest0,buf0,length0* sizeof(*dest0));
        }
    }
    *to = (_RoqmeDDSTopics_intseq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeIntContext__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeIntContext *from,
    struct _RoqmeDDSTopics_RoqmeIntContext *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_intseq__copyIn(c_type, const RoqmeDDSTopics::intseq *, _RoqmeDDSTopics_intseq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_intseq__copyIn(type0, &from->value(), &to->value);
    }
    return result;
}

v_copyin_result
__RoqmeDDSTopics_uintseq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::uintseq *from,
    _RoqmeDDSTopics_uintseq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_ulonglong *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_ulonglong *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1598 */
        if(length0 > 0)
        {
            const c_ulonglong *buf0;
            buf0 = reinterpret_cast<const c_ulonglong *>(&((*from)[0]));
            memcpy (dest0,buf0,length0* sizeof(*dest0));
        }
    }
    *to = (_RoqmeDDSTopics_uintseq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeUIntContext__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeUIntContext *from,
    struct _RoqmeDDSTopics_RoqmeUIntContext *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_uintseq__copyIn(c_type, const RoqmeDDSTopics::uintseq *, _RoqmeDDSTopics_uintseq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_uintseq__copyIn(type0, &from->value(), &to->value);
    }
    return result;
}

v_copyin_result
__RoqmeDDSTopics_doubleseq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::doubleseq *from,
    _RoqmeDDSTopics_doubleseq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_double *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_double *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1598 */
        if(length0 > 0)
        {
            const c_double *buf0;
            buf0 = reinterpret_cast<const c_double *>(&((*from)[0]));
            memcpy (dest0,buf0,length0* sizeof(*dest0));
        }
    }
    *to = (_RoqmeDDSTopics_doubleseq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeDoubleContext__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeDoubleContext *from,
    struct _RoqmeDDSTopics_RoqmeDoubleContext *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_doubleseq__copyIn(c_type, const RoqmeDDSTopics::doubleseq *, _RoqmeDDSTopics_doubleseq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_doubleseq__copyIn(type0, &from->value(), &to->value);
    }
    return result;
}

v_copyin_result
__RoqmeDDSTopics_boolseq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::boolseq *from,
    _RoqmeDDSTopics_boolseq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_bool *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_bool *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1629 */
        unsigned int i0;
        for (i0 = 0; (i0 < length0) && result; i0++) {
            dest0[i0] = (c_bool)(*from)[i0];
        }
    }
    *to = (_RoqmeDDSTopics_boolseq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeBoolContext__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeBoolContext *from,
    struct _RoqmeDDSTopics_RoqmeBoolContext *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_boolseq__copyIn(c_type, const RoqmeDDSTopics::boolseq *, _RoqmeDDSTopics_boolseq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_boolseq__copyIn(type0, &from->value(), &to->value);
    }
    return result;
}

v_copyin_result
__RoqmeDDSTopics_eventseq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::eventseq *from,
    _RoqmeDDSTopics_eventseq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_string *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_string *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1629 */
        unsigned int i0;
        for (i0 = 0; (i0 < length0) && result; i0++) {
                dest0[i0] = c_stringNew(c_getBase(dbType), (*from)[i0].c_str());
        }
    }
    *to = (_RoqmeDDSTopics_eventseq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeEventContext__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeEventContext *from,
    struct _RoqmeDDSTopics_RoqmeEventContext *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_eventseq__copyIn(c_type, const RoqmeDDSTopics::eventseq *, _RoqmeDDSTopics_eventseq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_eventseq__copyIn(type0, &from->value(), &to->value);
    }
    return result;
}

v_copyin_result
__RoqmeDDSTopics_enumseq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::enumseq *from,
    _RoqmeDDSTopics_enumseq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_string *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_string *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1629 */
        unsigned int i0;
        for (i0 = 0; (i0 < length0) && result; i0++) {
                dest0[i0] = c_stringNew(c_getBase(dbType), (*from)[i0].c_str());
        }
    }
    *to = (_RoqmeDDSTopics_enumseq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeEnumContext__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeEnumContext *from,
    struct _RoqmeDDSTopics_RoqmeEnumContext *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_enumseq__copyIn(c_type, const RoqmeDDSTopics::enumseq *, _RoqmeDDSTopics_enumseq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_enumseq__copyIn(type0, &from->value(), &to->value);
    }
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeObservation__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeObservation *from,
    struct _RoqmeDDSTopics_RoqmeObservation *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeEstimate__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeEstimate *from,
    struct _RoqmeDDSTopics_RoqmeEstimate *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->name = c_stringNew(c_getBase(dbType), from->name_.c_str());
    to->value = (c_double)from->value();
    return result;
}

v_copyin_result
__RoqmeDDSTopics_id_seq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::id_seq *from,
    _RoqmeDDSTopics_id_seq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_string *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_string *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1629 */
        unsigned int i0;
        for (i0 = 0; (i0 < length0) && result; i0++) {
                dest0[i0] = c_stringNew(c_getBase(dbType), (*from)[i0].c_str());
        }
    }
    *to = (_RoqmeDDSTopics_id_seq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_value_seq__copyIn(
    c_type dbType,
    const ::RoqmeDDSTopics::value_seq *from,
    _RoqmeDDSTopics_value_seq *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 2001 */

    c_type type0 = c_typeDef(dbType)->alias;
    c_double *dest0;

    c_ulong length0 = (*from).size();
    dest0 = (c_double *)c_newSequence(c_collectionType(type0), length0);
    {
        /* Code generated by /home/dds/OvernightTests/marcel/opensplice-test/tags/OSPL_V6_9_190705OSS-RC1/ubuntu1804-64a/x86_64.linux-release/build/src/tools/idlpp/code/idl_genISOCxx2Copyin.c at line 1598 */
        if(length0 > 0)
        {
            const c_double *buf0;
            buf0 = reinterpret_cast<const c_double *>(&((*from)[0]));
            memcpy (dest0,buf0,length0* sizeof(*dest0));
        }
    }
    *to = (_RoqmeDDSTopics_value_seq)dest0;
    return result;
}

v_copyin_result
__RoqmeDDSTopics_RoqmeRanking__copyIn(
    c_type dbType,
    const class ::RoqmeDDSTopics::RoqmeRanking *from,
    struct _RoqmeDDSTopics_RoqmeRanking *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) dbType;

    to->metricName = c_stringNew(c_getBase(dbType), from->metricName_.c_str());
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_id_seq__copyIn(c_type, const RoqmeDDSTopics::id_seq *, _RoqmeDDSTopics_id_seq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 1));
        result = __RoqmeDDSTopics_id_seq__copyIn(type0, &from->ids(), &to->ids);
    }
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __RoqmeDDSTopics_value_seq__copyIn(c_type, const RoqmeDDSTopics::value_seq *, _RoqmeDDSTopics_value_seq *);
        c_type type0 = c_memberType(c_structureMember(c_structure(dbType), 2));
        result = __RoqmeDDSTopics_value_seq__copyIn(type0, &from->values(), &to->values);
    }
    return result;
}

void
__RoqmeDDSTopics_intseq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_intseq *from = (const _RoqmeDDSTopics_intseq *)_from;
    ::RoqmeDDSTopics::intseq *to = (::RoqmeDDSTopics::intseq *)_to;
    long size0;
    const c_longlong *src0 = (const c_longlong *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
        (*to).assign(src0, src0 + size0);
}

void
__RoqmeDDSTopics_RoqmeIntContext__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeIntContext *from = (const struct _RoqmeDDSTopics_RoqmeIntContext *)_from;
    class ::RoqmeDDSTopics::RoqmeIntContext *to = (class ::RoqmeDDSTopics::RoqmeIntContext *)_to;
    to->name(from->name ? from->name : "");
    {
        extern void __RoqmeDDSTopics_intseq__copyOut(const void *, void *);
        RoqmeDDSTopics::intseq &tmp = to->value();
        __RoqmeDDSTopics_intseq__copyOut((const void *)&from->value, (void *)&tmp);
    }
}

void
__RoqmeDDSTopics_uintseq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_uintseq *from = (const _RoqmeDDSTopics_uintseq *)_from;
    ::RoqmeDDSTopics::uintseq *to = (::RoqmeDDSTopics::uintseq *)_to;
    long size0;
    const c_ulonglong *src0 = (const c_ulonglong *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
        (*to).assign(src0, src0 + size0);
}

void
__RoqmeDDSTopics_RoqmeUIntContext__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeUIntContext *from = (const struct _RoqmeDDSTopics_RoqmeUIntContext *)_from;
    class ::RoqmeDDSTopics::RoqmeUIntContext *to = (class ::RoqmeDDSTopics::RoqmeUIntContext *)_to;
    to->name(from->name ? from->name : "");
    {
        extern void __RoqmeDDSTopics_uintseq__copyOut(const void *, void *);
        RoqmeDDSTopics::uintseq &tmp = to->value();
        __RoqmeDDSTopics_uintseq__copyOut((const void *)&from->value, (void *)&tmp);
    }
}

void
__RoqmeDDSTopics_doubleseq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_doubleseq *from = (const _RoqmeDDSTopics_doubleseq *)_from;
    ::RoqmeDDSTopics::doubleseq *to = (::RoqmeDDSTopics::doubleseq *)_to;
    long size0;
    const c_double *src0 = (const c_double *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
        (*to).assign(src0, src0 + size0);
}

void
__RoqmeDDSTopics_RoqmeDoubleContext__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeDoubleContext *from = (const struct _RoqmeDDSTopics_RoqmeDoubleContext *)_from;
    class ::RoqmeDDSTopics::RoqmeDoubleContext *to = (class ::RoqmeDDSTopics::RoqmeDoubleContext *)_to;
    to->name(from->name ? from->name : "");
    {
        extern void __RoqmeDDSTopics_doubleseq__copyOut(const void *, void *);
        RoqmeDDSTopics::doubleseq &tmp = to->value();
        __RoqmeDDSTopics_doubleseq__copyOut((const void *)&from->value, (void *)&tmp);
    }
}

void
__RoqmeDDSTopics_boolseq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_boolseq *from = (const _RoqmeDDSTopics_boolseq *)_from;
    ::RoqmeDDSTopics::boolseq *to = (::RoqmeDDSTopics::boolseq *)_to;
    long size0;
    const c_bool *src0 = (const c_bool *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
    {
        long i0;
        for (i0 = 0; i0 < size0; i0++) {
            (*to).push_back((bool)src0[i0]);
        }
    }
}

void
__RoqmeDDSTopics_RoqmeBoolContext__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeBoolContext *from = (const struct _RoqmeDDSTopics_RoqmeBoolContext *)_from;
    class ::RoqmeDDSTopics::RoqmeBoolContext *to = (class ::RoqmeDDSTopics::RoqmeBoolContext *)_to;
    to->name(from->name ? from->name : "");
    {
        extern void __RoqmeDDSTopics_boolseq__copyOut(const void *, void *);
        RoqmeDDSTopics::boolseq &tmp = to->value();
        __RoqmeDDSTopics_boolseq__copyOut((const void *)&from->value, (void *)&tmp);
    }
}

void
__RoqmeDDSTopics_eventseq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_eventseq *from = (const _RoqmeDDSTopics_eventseq *)_from;
    ::RoqmeDDSTopics::eventseq *to = (::RoqmeDDSTopics::eventseq *)_to;
    long size0;
    const c_string *src0 = (const c_string *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
    {
        long i0;
        for (i0 = 0; i0 < size0; i0++) {
            (*to).push_back(src0[i0] ? src0[i0] : "");
        }
    }
}

void
__RoqmeDDSTopics_RoqmeEventContext__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeEventContext *from = (const struct _RoqmeDDSTopics_RoqmeEventContext *)_from;
    class ::RoqmeDDSTopics::RoqmeEventContext *to = (class ::RoqmeDDSTopics::RoqmeEventContext *)_to;
    to->name(from->name ? from->name : "");
    {
        extern void __RoqmeDDSTopics_eventseq__copyOut(const void *, void *);
        RoqmeDDSTopics::eventseq &tmp = to->value();
        __RoqmeDDSTopics_eventseq__copyOut((const void *)&from->value, (void *)&tmp);
    }
}

void
__RoqmeDDSTopics_enumseq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_enumseq *from = (const _RoqmeDDSTopics_enumseq *)_from;
    ::RoqmeDDSTopics::enumseq *to = (::RoqmeDDSTopics::enumseq *)_to;
    long size0;
    const c_string *src0 = (const c_string *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
    {
        long i0;
        for (i0 = 0; i0 < size0; i0++) {
            (*to).push_back(src0[i0] ? src0[i0] : "");
        }
    }
}

void
__RoqmeDDSTopics_RoqmeEnumContext__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeEnumContext *from = (const struct _RoqmeDDSTopics_RoqmeEnumContext *)_from;
    class ::RoqmeDDSTopics::RoqmeEnumContext *to = (class ::RoqmeDDSTopics::RoqmeEnumContext *)_to;
    to->name(from->name ? from->name : "");
    {
        extern void __RoqmeDDSTopics_enumseq__copyOut(const void *, void *);
        RoqmeDDSTopics::enumseq &tmp = to->value();
        __RoqmeDDSTopics_enumseq__copyOut((const void *)&from->value, (void *)&tmp);
    }
}

void
__RoqmeDDSTopics_RoqmeObservation__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeObservation *from = (const struct _RoqmeDDSTopics_RoqmeObservation *)_from;
    class ::RoqmeDDSTopics::RoqmeObservation *to = (class ::RoqmeDDSTopics::RoqmeObservation *)_to;
    to->name(from->name ? from->name : "");
}

void
__RoqmeDDSTopics_RoqmeEstimate__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeEstimate *from = (const struct _RoqmeDDSTopics_RoqmeEstimate *)_from;
    class ::RoqmeDDSTopics::RoqmeEstimate *to = (class ::RoqmeDDSTopics::RoqmeEstimate *)_to;
    to->name(from->name ? from->name : "");
    to->value((double)from->value);
}

void
__RoqmeDDSTopics_id_seq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_id_seq *from = (const _RoqmeDDSTopics_id_seq *)_from;
    ::RoqmeDDSTopics::id_seq *to = (::RoqmeDDSTopics::id_seq *)_to;
    long size0;
    const c_string *src0 = (const c_string *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
    {
        long i0;
        for (i0 = 0; i0 < size0; i0++) {
            (*to).push_back(src0[i0] ? src0[i0] : "");
        }
    }
}

void
__RoqmeDDSTopics_value_seq__copyOut(
    const void *_from,
    void *_to)
{
    const _RoqmeDDSTopics_value_seq *from = (const _RoqmeDDSTopics_value_seq *)_from;
    ::RoqmeDDSTopics::value_seq *to = (::RoqmeDDSTopics::value_seq *)_to;
    long size0;
    const c_double *src0 = (const c_double *)(*from);

    size0 = c_arraySize(c_sequence(src0));
    (*to).clear();
    (*to).reserve(size0);
        (*to).assign(src0, src0 + size0);
}

void
__RoqmeDDSTopics_RoqmeRanking__copyOut(
    const void *_from,
    void *_to)
{
    const struct _RoqmeDDSTopics_RoqmeRanking *from = (const struct _RoqmeDDSTopics_RoqmeRanking *)_from;
    class ::RoqmeDDSTopics::RoqmeRanking *to = (class ::RoqmeDDSTopics::RoqmeRanking *)_to;
    to->metricName(from->metricName ? from->metricName : "");
    {
        extern void __RoqmeDDSTopics_id_seq__copyOut(const void *, void *);
        RoqmeDDSTopics::id_seq &tmp = to->ids();
        __RoqmeDDSTopics_id_seq__copyOut((const void *)&from->ids, (void *)&tmp);
    }
    {
        extern void __RoqmeDDSTopics_value_seq__copyOut(const void *, void *);
        RoqmeDDSTopics::value_seq &tmp = to->values();
        __RoqmeDDSTopics_value_seq__copyOut((const void *)&from->values, (void *)&tmp);
    }
}
