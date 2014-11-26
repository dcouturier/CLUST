echo "Testing raw sinoscope execution"
./../sinoscope/src/sinoscope --cmd benchmark --width 1024 --height 1024 --iter 100000

echo "Testion sinoscope with libCLUST.so in LD_PRELOAD without tracing"
LD_PRELOAD=./src/.libs/libCLUST.so ./../sinoscope/src/sinoscope --cmd benchmark --width 1024 --height 1024 --iter 100000

echo "Testing sinoscope with libCLUST.so is LD_PRELOAD with user space tracing anabled"
lttng create sinoscope_clust
lttng enable-event -a -u
lttng start
LD_PRELOAD=./src/.libs/libCLUST.so ./../sinoscope/src/sinoscope --cmd benchmark --width 1024 --height 1024 --iter 100000
lttng stop
lttng destroy sinoscope_clust
