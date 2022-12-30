실행방법
gcc -pg sum.c -o sum
./sum
gprof sum>sum.gprof
vi sum.gprof

수행할 내용
cp sum.c sum_opt.c
gcc -pg sum_opt.c -o sum_opt
./sum_opt
gprof sum_opt > sum_opt.gprof
vi sum_opt.gprof


