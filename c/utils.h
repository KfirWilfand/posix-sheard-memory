struct param_struct {
    char shared_memory_name[512];
    int permissions;
    int size;
};


void read_params(struct param_struct *);


