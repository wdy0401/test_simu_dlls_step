#ifndef PCP_TACTIC_GLOBAL_H
#define PCP_TACTIC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PCP_TACTIC_LIBRARY)
#  define PCP_TACTICSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PCP_TACTICSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PCP_TACTIC_GLOBAL_H

#ifndef PCP_TACTIC_H
#define PCP_TACTIC_H

class PCP_TACTICSHARED_EXPORT pcp_tactic
{

public:
    pcp_tactic();
};

#endif // PCP_TACTIC_H
