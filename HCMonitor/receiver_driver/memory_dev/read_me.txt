1 ��ʼ��׼��

   make

   ./memory_dev_load

2 �ռ�trace

   gcc -o trace_collect collect_kerner_trace.c

   ./trace_collect filename

3 ����trace

   gcc -o trace_analyze trace_analyze_huawei.c

   ./trace_analyze filename rw 0 all n
   ���������ԭʼtrace�������ͬ��·����