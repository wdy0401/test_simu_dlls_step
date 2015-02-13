#if defined(DG_TACTIC_LIBRARY)
#  define DG_TACTICSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DG_TACTICSHARED_EXPORT Q_DECL_IMPORT
#endif


#ifndef DG_TACTIC_H
#define DG_TACTIC_H

#include"../tactic/tactic.h"

class DG_TACTICSHARED_EXPORT DG_tactic: public tactic
{
public:
    DG_tactic();
};

#endif // DG_TACTIC_H
