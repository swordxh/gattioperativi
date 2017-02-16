#include "mikabooq.h"
#include "const.h"

typedef struct elem_pcbt {
	struct pcb_t elem;
	struct list_head list;

} elem_pcbt;

elem_pcbt vet_pcbt[MAXPROC];
struct list_head head_pcbt_libera;

struct pcb_t *proc_init(void){
    
    INIT_LIST_HEAD(&head_pcbt_libera);
    for (int i=1; i<MAXPROC; i++){
        list_add(&(vet_pcbt[i].list) ,&head_pcbt_libera);
    }
    (vet_pcbt[0].elem).p_parent=NULL;
    return vet_pcbt[0]->elem;
}


struct pcb_t *proc_alloc(struct pcb_t *p_parent){
    if ((p_parent==NULL) || (list_empty(&head_pcbt_libera)));return NULL;
    struct pcb_t *current_pcbt=&((container_of((head_pcbt_libera.next, elem_pcbt, list).elem);
    list_del(&head_pcbt_libera.next);
    current_pcbt->p_parent=p_parent;
    return current_pcbt;
    
}

int proc_delete(struct pcb_t *oldproc){
    
    
}
