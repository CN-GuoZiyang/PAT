#include<iostream>
#include<algorithm>
#include<vector> 

using namespace std;

struct member{
	int arrivingTime;
	int playingTime;
	int vip;
	int waitingTime;
	int startTime; 
	int haveTable;
	int num;
};

struct table{
	int endTime;
	int totalPeople;
	int vip; 
};

bool cmp(member a,member b){
	return a.arrivingTime<b.arrivingTime;
}

bool cmp2(member a,member b){
	return a.startTime<b.startTime;
}

vector<member> waitQueue;
table tables[101];

int main(){
	int N,M,K;
 	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			// 输入数据 
			member temp;
			int hh,mm,ss;
			scanf("%d:%d:%d%d%d",&hh,&mm,&ss,&temp.playingTime,&temp.vip);
			temp.arrivingTime = hh*3600+mm*60+ss;
			temp.playingTime = (temp.playingTime>120?120*60:temp.playingTime*60);
			temp.haveTable = -1;
			temp.startTime = 21*3600;
			temp.num = i+1;
			waitQueue.push_back(temp);
		}
		table initTable{8*3600,0,0};
		fill(tables,tables+101,initTable);
		scanf("%d%d",&K,&M);
		for(int i=0;i<M;i++){
			int temp;
			scanf("%d",&temp);
			tables[temp-1].vip = 1;
		}
		sort(waitQueue.begin(),waitQueue.end(),cmp);
		/* -------------分配策略---------------*/		
		for(auto it = waitQueue.begin();it!=waitQueue.end();){
			// 分配第it个会员
			auto it_current = it;// it是遍历整个排队队列的主指针，it_current是临时指针，指向每一次遍历需要安排的会员 
			int min_endTime = 21*3600;// min_endTime 负责记录最早空闲出来的桌子的时间 
			int postion = 0;// postion记录最终分派的桌子的位置 
			bool novip = true;
			// 从K个桌子中遍历最早空闲的桌子，如果存在多个桌子，选择最小的那个 
			for(int i=0;i<K;i++){
				if(min_endTime>tables[i].endTime){
					postion = i;
					min_endTime = tables[i].endTime;
				}
			}
			if(tables[postion].endTime>=21*3600)// 如果最早空出来的桌子都超过了21点，显然此时任何一个桌子都不能再分配 
				break;
			// 选出合适的位置了之后，开始判断，先看桌子是不是VIP桌子，如果是，再看目前排队的人有没有VIP 
			if(tables[postion].vip){
				//【第一大类】最先空出来的桌子是VIP桌子，
				// 那么下一步判断在该桌子空闲的过程中，it_current身后排队的人群中有没有VIP，如果有，VIP优先于当前
				for(;it_current!=waitQueue.end()&&it_current->arrivingTime<=min_endTime;it_current++){
					if(it_current->vip&&it_current->haveTable==-1){
						//【1】 VIP桌子，存在到场的VIP会员，分配该桌子给VIP 
						//cout<<"num = "<<it_current->num<<" positon = "<<postion<<endl;
						it_current->haveTable = postion;
						novip = false;
						break;// 此时it指针不能移动，因为可能vip在很后面的位置，如果移动，当前节点就会被跳过 ，标记该VIP已经被分配过即可 
					}
				} 
				if(novip){
					//【2】VIP桌子，但是不存在到场的VIP会员，那么分配给排队的第一个人 
					it_current = it;
					it_current->haveTable = postion;
					it++;
				}
			}else{//【第二大类】最先空出来的不是VIP桌 
				// 如果当前的会员不是VIP，非VIP球桌分配给非VIP会员，直接分配
				if(it_current->vip!=1){
					it_current->haveTable = postion;
					it++;
				}else{// 如果当前排队的是VIP，那么需要确认是否存在其他空闲的VIP桌子 
					int vipTable = -1;
					for(int i=0;i<K;i++){
						if(tables[i].vip&&tables[i].endTime<=it_current->arrivingTime){
							vipTable = i;
							break;
						}
					} 
					// 存在VIP空闲桌，那么给VIP分配VIP桌子 
					if(vipTable!=-1){
						//cout<<"vipTable = "<<vipTable<<" num = "<<it_current->num<<endl;
						it_current->haveTable = vipTable;
						postion = vipTable; 
					}else{// 不存在VIP桌，只能分配普通桌 
						if(it_current->haveTable==-1){
							it_current->haveTable = postion; 
							//cout<<"postion = "<<postion<<" num = "<<it_current->num<<endl;
						}else{
							it++;
							continue;
						}
					}
					it++;
				} 
			}
			// 更新会员数据，如果到的时候，是空闲的，那么以到的时间为开始时间，否则以桌子的空闲时间为开始时间 
			it_current->startTime = min_endTime>it_current->arrivingTime?min_endTime:it_current->arrivingTime;
			it_current->waitingTime = min_endTime<=it_current->arrivingTime? 0:min_endTime-it_current->arrivingTime;			
			// 更新桌子的数据，结束时间以当前使用者开始使用+使用时间为准 
			tables[postion].endTime = it_current->startTime+it_current->playingTime; 
			if(it_current->startTime<21*3600)
				tables[postion].totalPeople++;
		}
		/* -------------输出---------------*/
		sort(waitQueue.begin(),waitQueue.end(),cmp2);
		for(auto elem:waitQueue){
			if(elem.startTime>=21*3600) continue;
			int hh1 = elem.arrivingTime/3600;
			int mm1 = (elem.arrivingTime - hh1*3600)/60;
			int ss1 = elem.arrivingTime - mm1*60 - hh1*3600;
			int hh2 = elem.startTime/3600;
			int mm2 = (elem.startTime - hh2*3600)/60;
			int ss2 = elem.startTime - mm2*60 - hh2*3600;
			int waitingTime = elem.waitingTime/60 +((elem.waitingTime%60>=30)? 1:0);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",hh1,mm1,ss1,hh2,mm2,ss2,waitingTime);
		} 
		printf("%d",tables[0].totalPeople);
		for(int i=1;i<K;i++){
			printf(" %d",tables[i].totalPeople);
		}
	}
	return 0;
}