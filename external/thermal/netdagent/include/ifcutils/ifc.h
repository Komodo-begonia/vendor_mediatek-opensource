#ifndef _IFC_H_
#define _IFC_H_

__BEGIN_DECLS

extern int ifc_set_txq_state(const char *ifname, int state);
extern int ifc_ccmni_md_cfg(const char *ifname, int md_id);
int ifc_enable_ack_prio(int enable);

__END_DECLS

#endif /* _IFC_H_ */
