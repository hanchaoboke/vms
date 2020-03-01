objs = ttest.o protest.o tttfuction.o
  
test: $(objs)
	cc $(objs) -o test

.PHONY: clean

clean:
	rm -f $(objs) test
