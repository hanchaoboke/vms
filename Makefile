objs = vms.o customer.o administrator.o
  
vms: $(objs)
	cc $(objs) -o vms

.PHONY: clean

clean:
	rm -f $(objs) vms
