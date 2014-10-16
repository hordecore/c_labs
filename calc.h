/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALC_H_RPCGEN
#define _CALC_H_RPCGEN

#include <rpc/rpc.h>

#define DAEMONIZE
#ifdef DAEMONIZE
#include <syslog.h> 
#define LOG(...) syslog(LOG_NOTICE, __VA_ARGS__)
#else
#define LOG(...) printf(__VA_ARGS__)
#endif

#ifdef __cplusplus
extern "C" {
#endif


struct mypair {
	double arg1;
	double arg2;
};
typedef struct mypair mypair;

#define MCPROG 0x20000002
#define MCVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADD 1
extern  double * add_1(mypair *, CLIENT *);
extern  double * add_1_svc(mypair *, struct svc_req *);
#define SUBTRACT 2
extern  double * subtract_1(mypair *, CLIENT *);
extern  double * subtract_1_svc(mypair *, struct svc_req *);
#define MULTIPLE 3
extern  double * multiple_1(mypair *, CLIENT *);
extern  double * multiple_1_svc(mypair *, struct svc_req *);
#define DIVIDE 4
extern  double * divide_1(mypair *, CLIENT *);
extern  double * divide_1_svc(mypair *, struct svc_req *);
extern double mcprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADD 1
extern  double * add_1();
extern  double * add_1_svc();
#define SUBTRACT 2
extern  double * subtract_1();
extern  double * subtract_1_svc();
#define MULTIPLE 3
extern  double * multiple_1();
extern  double * multiple_1_svc();
#define DIVIDE 4
extern  double * divide_1();
extern  double * divide_1_svc();
extern double mcprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_mypair (XDR *, mypair*);

#else /* K&R C */
extern bool_t xdr_mypair ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALC_H_RPCGEN */