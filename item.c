{
/****************      �K���ȃA�C�e��ID��T��         ***************************************************************/
int search_item(int object){
	char file_name[40];
	char strgat[80];
	char gomi[40];
	FILE *fp;
	int scount=0,fcount=0,nameid=0;
	
	printf("object:%d\n",object);
	if(object==1){
		strcpy(file_name,"item_all.list");
		scount = (int)(((double)rand()/(double)RAND_MAX)*1061.0);
		printf("scount:%d\n",scount);
	}else if(object==2){
		strcpy(file_name,"item_equipment.list");
		scount = (int)(((double)rand()/(double)RAND_MAX)*490.0);
	}else if(object==3){
		strcpy(file_name,"item_card.list");
		scount = (int)(((double)rand()/(double)RAND_MAX)*149.0);
	}else if(object==4){
		strcpy(file_name,"item_present.list");
		scount = (int)(((double)rand()/(double)RAND_MAX)*77.0);
	}
	if((fp = fopen(file_name,"r"))==NULL){
		printf("�I�[�v���ł��˂����A(߄D� )��٧!!\n");
	}
	for(fcount=0;fcount<scount;fcount++){//�t�@�C����scount�s�ڂ܂ł�����
		fgets(strgat,80,fp);
	}
	fclose(fp);
	sscanf(strgat,"%d%s",&nameid,gomi);
	printf("�A�C�e��ID:%d          �A�C�e����:%s\n",nameid,gomi);
	return nameid;
}


/**************   �w�肵���A�C�e��ID�����݂��邩�`�F�b�N   ************************************/
int is_item(int object){
	char str[80];
	FILE *fp;
	int item_id=0,result=0;
	
	if((fp = fopen("item_all.list","r"))==NULL){
		printf("�I�[�v���ł��˂����A(߄D� )��٧!!\n");
	}
	while(fgets(str,80,fp)!=NULL){
		sscanf(str,"%d",&item_id);
		if(item_id==object){
			result=1;//��������
				break;
		}
	}
	fclose(fp);
	return result;
}
/**********************************************************************************************/

/**************   �A�C�e���g�p    *************************************************************/
     	int nameid=p->inventory[RFIFOW(fd,2)-2].nameid;
     	short option;
     	double bonus=0;//Vit�ɂ��񕜗ʕ␳
     	item_num = itemdb_type(p->inventory[RFIFOW(fd,2)-2].nameid);//inventory�@������
  		p=&sd->status;
     	if(item_num==0){//�񕜃A�C�e���Ȃ��
			WFIFOW(fd,0) = 0xa8;
			WFIFOW(fd,2) = RFIFOW(fd,2);
			WFIFOW(fd,4) = --p->inventory[RFIFOW(fd,2)-2].amount;
			WFIFOB(fd,6) = 01;
			WFIFOSET(fd,7);
			if(p->inventory[RFIFOW(fd,2)-2].amount <= 0){
				p->inventory[RFIFOW(fd,2)-2].nameid=0;
			}
			//�񕜗ʁ@=�@�i�A�C�e���̊�{�񕜗ʂ�1�j*�i1 + VIT/100 + �񕜃X�L�����x��/10)
				if(p->skill[3].lv >= 1){
					bonus = ((double)p->skill[3].lv)/10.0;
				}
				bonus += ((double)(p->vit+100)/(double)100);
			//srand((unsigned)time(NULL));//��������
			if(nameid==501){//�ԃ|�[�V����
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 44)+30) * bonus;
			}else if(nameid==502){//�g�|�[�V����
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 69)+50) * bonus;
			}else if(nameid==503){//���F�|�[�V����
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 104)+80) * bonus;
			}else if(nameid==504){//���|�[�V����
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 120)+149) * bonus;
			}else if(nameid==505){//�|�[�V����
				p->sp += (double)((((double)rand()/(double)RAND_MAX) * 45)+53);
			}else if(nameid==506){//�΃|�[�V�����@�@�ŉ�
				option = 0x0038;
				p->option = p->option & option;//�y�R�A�J�[�g�A��ȊO�̃t���O����
				WFIFOW(fd,0)=0x0119;
				WFIFOL(fd,2)=sd->account_id;
				WFIFOW(fd,6)=0;
				WFIFOW(fd,8)=0;
				WFIFOW(fd,10)=p->option;
			mmo_map_sendarea( fd, WFIFOP(fd,0),packet_len_table[0x0119], 0 );
			}else if(nameid==507){//�ԃn�[�u
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 12)+19) * bonus;
			}else if(nameid==508){//���F�n�[�u
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 21)+29) * bonus;
			}else if(nameid==509){//���n�[�u
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 50)+50) * bonus;
			}else if(nameid==510){//�n�[�u
				p->sp += (double)((((double)rand()/(double)RAND_MAX) * 10)+17);
			}else if(nameid==511){//�΃n�[�u�@�@�ŉ�
				option = 0x0038;
				p->option = p->option & option;//�y�R�A�J�[�g�A��ȊO�̃t���O����
				WFIFOW(fd,0)=0x0119;
				WFIFOL(fd,2)=sd->account_id;
				WFIFOW(fd,6)=0;
				WFIFOW(fd,8)=0;
				WFIFOW(fd,10)=p->option;
			mmo_map_sendarea( fd, WFIFOP(fd,0),packet_len_table[0x0119], 0 );
			}else if(nameid==512){//���
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 12)+15) * bonus;
			}else if(nameid==513){//�o�i�i
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 11)+15) * bonus;
			}else if(nameid==514){//�u�h�E
				p->sp += (double)((((double)rand()/(double)RAND_MAX) * 8)+11);
			}else if(nameid==515){//�ɂ񂶂�
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 13)+15) * bonus;
			}else if(nameid==516){//��
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 10)+14) * bonus;
			}else if(nameid==517){//��
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 41)+55) * bonus;
			}else if(nameid==518){//�I�̖�
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 46)+66) * bonus;
				p->sp += (double)((((double)rand()/(double)RAND_MAX) * 5)+9);
			}else if(nameid==519){//�~���N
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 15)+22) * bonus;
			}else if(nameid==520){//�q�i���̗t
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 60)+22) * bonus;
			}else if(nameid==521){//�A���G�̗t
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 150)+25) * bonus;
			}else if(nameid==522){//�}�X�e���̎�
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 200)+200) * bonus;
			}else if(nameid==523){//�����@�@�]���r����
				option = 0x0038;
				p->option = p->option & option;//�y�R�A�J�[�g�A��ȊO�̃t���O����
				WFIFOW(fd,0)=0x0119;
				WFIFOL(fd,2)=sd->account_id;
				WFIFOW(fd,6)=0;
				WFIFOW(fd,8)=0;
				WFIFOW(fd,10)=p->option;
			mmo_map_sendarea( fd, WFIFOP(fd,0),packet_len_table[0x0119], 0 );
			}else if(nameid==525){//���\��@�@�ُ��ԉ�
				option = 0x0038;
				p->option = p->option & option;//�y�R�A�J�[�g�A��ȊO�̃t���O����
				WFIFOW(fd,0)=0x0119;
				WFIFOL(fd,2)=sd->account_id;
				WFIFOW(fd,6)=0;
				WFIFOW(fd,8)=0;
				WFIFOW(fd,10)=p->option;
			mmo_map_sendarea( fd, WFIFOP(fd,0),packet_len_table[0x0119], 0 );
			}else if(nameid==526){//���[�����[���[�@�@HP�ASP�S��
				p->sp = p->max_sp;
				p->hp = p->max_hp;
			}else if(nameid==528){//�������̉a
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 41)+55) * bonus;
			}else if(nameid==529){//�L�����f�B
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 30)+44) * bonus;
			}else if(nameid==530){//�X�e�B�b�N�L�����f�B
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 60)+88) * bonus;
			}else if(nameid==531){//�����S�W���[�X
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 15)+22) * bonus;
			}else if(nameid==532){//�o�i�i�W���[�X
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 15)+22) * bonus;
			}else if(nameid==533){//�u�h�E�W���[�X
				p->sp += (double)((((double)rand()/(double)RAND_MAX) * 30)+22);
			}else if(nameid==534){//�ɂ񂶂�W���[�X
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 15)+22) * bonus;
			}else if(nameid==535){//�J�{�`��
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 12)+15) * bonus;
			}else if(nameid==536){//�A�C�X�N���[��
				p->sp += (double)((((double)rand()/(double)RAND_MAX) * 150)+10) * bonus;
			}else if(nameid==538){//�悭�Ă����N�b�L�[
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 500)+10) * bonus;
			}else if(nameid==539){//�ЂƂ����P�[�L
				p->hp += (double)((((double)rand()/(double)RAND_MAX) * 1500)+10) * bonus;
			}

			if(p->hp > p->max_hp){//�ő�HP�𒴂�����
				p->hp = p->max_hp;//�ő�HP���x�ɐݒ肵�Ȃ���
			}
			if(p->sp > p->max_sp){//�ő�SP�𒴂�����
				p->sp = p->max_sp;//�ő�SP���x�ɐݒ肵�Ȃ���
			}
			
/*
R 00b0 <type>.w <val>.l
	�F�X�Ȕ\�͒l�̍X�V�B�ȉ�type:�Ή����鐔�l���
	0000:speed 0003:���s�l 0004:�}�i�[�|�C���g 0005:HP 0006:MaxHP
	0007:SP 0008:MaxSP 0009:�X�e�[�^�X�|�C���g 000b:�x�[�X���x��
	000c:�X�L���|�C���g 0018:�d��(�\������Ă鐔����10�{)
	0019:�ő�d��(�\������Ă鐔����10�{)
	0029:ATK�O 002a:ATK�� 002b:MATK�O 002c:MATK��
	002d:DEF�O 002e:DEF�� 002f:MDEF�O 0030:MDEF��
	0031:HIT 0032:FLEE�O 0033:FLEE�� 0034:�N���e�B�J��
	0035:ASPD(2ms�P�ʂ̎���?) 0037:�W���u���x��
	0082:�� ATK��Ɠ�������?
*/
				WFIFOW(fd,0) = 0xb0;
				WFIFOW(fd,2) = 0005;
				WFIFOL(fd,4) = p->hp;
				WFIFOSET(fd,8);
				
				WFIFOW(fd,0) = 0xb0;
				WFIFOW(fd,2) = 0007;
				WFIFOL(fd,4) = p->sp;
				WFIFOSET(fd,8);
				
     }else if(item_num==2){//������ʂ����g�p�A�C�e���Ȃ��
     	 	WFIFOW(fd,0) = 0xa8;
			WFIFOW(fd,2) = RFIFOW(fd,2);
			WFIFOW(fd,4) = --p->inventory[RFIFOW(fd,2)-2].amount;
			WFIFOB(fd,6) = 01;
			WFIFOSET(fd,7);
			if(p->inventory[RFIFOW(fd,2)-2].amount <= 0){
				p->inventory[RFIFOW(fd,2)-2].nameid=0;
			}
			if(nameid==602){//���̉H
				mmo_map_changemap(fd,sd,p->save_point.map,p->save_point.x,p->save_point.y,2);
			}else if(nameid==601){//�n�G�̉H
				srand((unsigned)time(NULL));
				sd->x = (double)(((double)rand()/(double)RAND_MAX) * 300);
				srand((unsigned)time(NULL));
				sd->y = (double)(((double)rand()/(double)RAND_MAX) * 300);
				mmo_map_changemap(fd,sd,sd->mapname,sd->x,sd->y,2);
			}else if(nameid==611){//���ዾ
				int i,c;
				WFIFOW(fd,0) = 0x177;
				for(i=c=0;i<100;i++)
					//���Ӓ�A�C�e���Ȃ��
					if(sd->status.inventory[i].identify != 1)
					{
						WFIFOW(fd,4+c*2) = i+2;//sd->status.inventory[i].nameid;
						c++;
					}
				WFIFOW(fd,2) = 4+c*2;
				WFIFOSET(fd,4+c*2);
			}else if(nameid==604){//�Ö؂̎}�@�@�����_���œG������
				/*
				int mapno,npc;
				unsigned char buf[256];
				mapno = sd->mapno;
				npc = (double)(((double)rand()/(double)RAND_MAX) * 250) + 1001;
				map_data[sd->mapno].npc[npc]->x = sd->x;
				map_data[sd->mapno].npc[npc]->y = sd->y;
				map_data[mapno].npc[map_data[mapno].npc_num]=malloc(sizeof(struct npc_data));
			    map_data[mapno].npc[map_data[mapno].npc_num]->u.mons.speed=200;
				map_data[mapno].npc[map_data[mapno].npc_num]->class=npc;
				map_data[mapno].npc[map_data[mapno].npc_num]->id=npc;
				map_data[mapno].npc[map_data[mapno].npc_num]->block.subtype=MONS;
				map_data[mapno].npc[map_data[mapno].npc_num]->u.mons.hp=10;
				map_data[mapno].npc[map_data[mapno].npc_num]->u.mons.script = 1;
				memcpy(map_data[mapno].npc[map_data[mapno].npc_num]->name,npc,24);
				respawn_mons2(mapno,map_data[mapno].npc_num);
				map_data[mapno].npc_num++;
				*/
			}else if(nameid==605){//�A���e�B�y�C�������g �@�C���f���A�̌���
				WFIFOW(fd,0) = 0x147;
				WFIFOW(fd,2) = 8;
				WFIFOW(fd,4) = skill_db[8].type_inf;
				WFIFOW(fd,6) = 0;
				WFIFOW(fd,8) = 1;
				WFIFOW(fd,10) = skill_db[8].sp;
				WFIFOW(fd,12) = skill_db[8].range;
				memcpy(WFIFOP(fd,14),"�A���e�B�y�C�������g",24);
				WFIFOB(fd,38) = 0;
				mmo_map_sendarea(fd,WFIFOP(fd,0),39,0);
			}else if(nameid==606){//�A���G�x���@�@SP�S��
				p->sp = p->max_sp;
				WFIFOW(fd,0) = 0xb0;
				WFIFOW(fd,2) = 0007;
				WFIFOL(fd,4) = p->sp;
				WFIFOSET(fd,8);
			}else if(nameid==607){//�C�O�h���V���̎�  HP,SP�S��
					p->hp = p->max_hp;
					p->sp = p->max_sp;
					WFIFOW(fd,0) = 0xb0;
					WFIFOW(fd,2) = 0005;
					WFIFOL(fd,4) = p->hp;
					WFIFOSET(fd,8);
				
					WFIFOW(fd,0) = 0xb0;
					WFIFOW(fd,2) = 0007;
					WFIFOL(fd,4) = p->sp;
					WFIFOSET(fd,8);
			}else if(nameid==608){//�C�O�h���V���̎�@�@HP�ASP�@����
					p->hp += p->max_hp/2;
					p->sp += p->max_sp/2;
					if(p->hp > p->max_hp)p->hp = p->max_hp;
					if(p->sp > p->max_sp)p->sp = p->max_sp;
					WFIFOW(fd,0) = 0xb0;
					WFIFOW(fd,2) = 0005;
					WFIFOL(fd,4) = p->hp;
					WFIFOSET(fd,8);
				
					WFIFOW(fd,0) = 0xb0;
					WFIFOW(fd,2) = 0007;
					WFIFOL(fd,4) = p->sp;
					WFIFOSET(fd,8);
			}else if(nameid==609){//�ύ��̂��D  ������
				
			}else if(nameid==610){//�C�O�h���V���̗t�@�@�����Ԃ���HP1
				WFIFOW(fd,0) = 0x147;
				WFIFOW(fd,2) = 54;
				WFIFOW(fd,4) = skill_db[54].type_inf;
				WFIFOW(fd,6) = 0;
				WFIFOW(fd,8) = 1;
				WFIFOW(fd,10) = skill_db[54].sp;
				WFIFOW(fd,12) = skill_db[54].range;
				memcpy(WFIFOP(fd,14),"�C�O�h���V���̗t",24);
				WFIFOB(fd,38) = 0;
				mmo_map_sendarea(fd,WFIFOP(fd,0),39,0);
			}else if(nameid==603){//�����@�@�����_���ŃA�C�e�������
					int i1=502,i2=1,len=0;
					struct item tmp_item;
				i1 = search_item(1);
				if(i1>7000 || (619 <= i1 && i1 <= 643) || 
					(1256 <= i1 && i1<=1261)){i1=644;}//7000�Ԉȍ~�͖������ȕ����������s����Ȃ��߁A���͖������Ƃ��Ă���
      			memset(&tmp_item,0,sizeof(tmp_item));
      			tmp_item.nameid=i1;
      			tmp_item.amount=i2;
      			tmp_item.identify=1;
      			len=mmo_map_item_get(fd,WFIFOP(fd,0),&tmp_item);
      			if(len>0) WFIFOSET(fd,len);
			}else if(nameid==616){//�Â��J�[�h���@�@�����_���ŃJ�[�h�����
					int i1=502,i2=1,len=0;
					struct item tmp_item;
				i1 = search_item(3);
				if(i1>7000 || (619 <= i1 && i1 <= 643) || 
					(1256 <= i1 && i1<=1261)){i1=644;}//7000�Ԉȍ~�͖������ȕ����������s����Ȃ��߁A���͖������Ƃ��Ă���
      			memset(&tmp_item,0,sizeof(tmp_item));
      			tmp_item.nameid=i1;
      			tmp_item.amount=i2;
      			tmp_item.identify=1;
      			len=mmo_map_item_get(fd,WFIFOP(fd,0),&tmp_item);
      			if(len>0) WFIFOSET(fd,len);
			}else if(nameid==617){//�Â����F�̔�   �����_���ő����i�����
					int i1=502,i2=1,len=0;
					struct item tmp_item;
				i1 = search_item(2);
				if(i1>7000 || (619 <= i1 && i1 <= 643) || 
					(1256 <= i1 && i1<=1261)){i1=644;}//7000�Ԉȍ~�͖������ȕ����������s����Ȃ��߁A���͖������Ƃ��Ă���
      			memset(&tmp_item,0,sizeof(tmp_item));
      			tmp_item.nameid=i1;
      			tmp_item.amount=i2;
      			tmp_item.identify=1;
      			len=mmo_map_item_get(fd,WFIFOP(fd,0),&tmp_item);
      			if(len>0) WFIFOSET(fd,len);
			}else if(nameid==618){//�Â�����
					int i1=502,i2=1,len=0;
					struct item tmp_item;
				i1 = search_item(3);
				if(i1>7000 || (619 <= i1 && i1 <= 643) || 
					(1256 <= i1 && i1<=1261)){i1=644;}//7000�Ԉȍ~�͖������ȕ����������s����
      			memset(&tmp_item,0,sizeof(tmp_item));
      			tmp_item.nameid=i1;
      			tmp_item.amount=i2;
      			tmp_item.identify=1;
      			len=mmo_map_item_get(fd,WFIFOP(fd,0),&tmp_item);
      			if(len>0) WFIFOSET(fd,len);
			}else if(nameid==644){//�v���[���g�{�b�N�X �����_���Œ��M�d�i(�J�[�h�A�����A���Օi)	�����ł���
					int i1=502,i2=1,len=0;
					struct item tmp_item;
				i1 = search_item(4);
				if(i1>7000 || (619 <= i1 && i1 <= 643) || 
					(1256 <= i1 && i1<=1261)){i1=644;}//7000�Ԉȍ~�͖������ȕ����������s����Ȃ��߁A���͖������Ƃ��Ă���
      			memset(&tmp_item,0,sizeof(tmp_item));
      			tmp_item.nameid=i1;
      			tmp_item.amount=i2;
      			tmp_item.identify=1;
      			len=mmo_map_item_get(fd,WFIFOP(fd,0),&tmp_item);
      			if(len>0) WFIFOSET(fd,len);
			}else if(nameid == 643){// ADDED on 04/09/2003 --------------
				int i,c;
				WFIFOW(fd,0) = 0x1a6;
				for(i=c=0;i<100;i++)
					//�^�}�S�Ȃ��
					if((sd->status.inventory[i].nameid >= 9001)&&(sd->status.inventory[i].nameid <=9024))
					{
						WFIFOW(fd,4+c*2) = i+2;//sd->status.inventory[i].nameid;
						c++;
					}
				WFIFOW(fd,2) = 4+c*2;
				WFIFOSET(fd,4+c*2);


				//WFIFOW(fd,0) = 0x1a6;
				//WFIFOW(fd,2) = 6;
				//WFIFOW(fd,4) = RFIFOW(fd,2);
				//WFIFOSET(fd,6);
				//printf("index=%d\n",RFIFOW(fd,2));
				// --------------------------------------------------
			}
     }else{
     	 	if(nameid==714){//�G���y���E���@�@�M���h�쐬
     	 		
     	 	}
     }

}
/********************************************************************************************/
