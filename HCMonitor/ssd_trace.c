#include "monitor.h"

int trans_pcap(struct rte_mbuf *m, struct timespec ts_now, int lcore_id)	
{
	 int ret;
     char *buff = rte_pktmbuf_mtod(m, char*);
	 pcap_t pp;
	 
	 if(likely((PP_Ring[lcore_id]->occupy + 1) % SSD_NUM != PP_Ring[lcore_id]->deque)){
     	pp = PP_Ring[lcore_id]->ring[PP_Ring[lcore_id]->occupy];
        //memcpy(m, ssd, sizeof(struct rte_mbuf));
		pp->buff = buff;
		pp->ph.ts.ts_sec = ts_now.tv_sec;
		pp->ph.ts.ts_usec = ts_now.tv_nsec / 1000;
		pp->ph.capture_len = m->pkt_len;
		pp->ph.len = m->pkt_len;
        PP_Ring[lcore_id]->occupy = (SSD_Ring[lcore_id]->occupy + 1) & SSD_NUM;
        _mm_sfence();
     }else{
        printf("EXCP:PCAP buffer is Full!\n");
     }

     /*ret = fwrite(&ph, sizeof(pcap_header), 1, fp_out);
     ret = fwrite(buff, 1, ph.capture_len, fp_out);*/
	 return 0;
}

int ssd_pcap()
{
		
}
