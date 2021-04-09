#include <stdio.h>


/* déclaration fonction */
void resteAppreAchat(int norm_dura_t, int t_r, int t_p, int t_m, int t_j, int gain_r, int pristines_by_day, int matrix_by_day, int pages_by_day, int augment_base_gain, int tier, int *reste_r, int *reste_p, int *reste_m, int *reste_j);
int timeMiniTier(int t_r, int t_p, int t_m, int t_j, int gain_r, int pristines_by_day, int matrix_by_day, float pages_by_day, int augment_base_gain, int tier);
int coutMoinReste(int t_r, int *reste);
void m_to_r(int *t_r, int *t_m, int gain_r, int augment, int matrix_by_day, int *r_to_m_t);



// Raw data


int main(void) {



/* Input déclaration */

	int relics = 0;
	int pristines = 0;
	int matrix = 0;
	int journals = 0;
	int pages = 0 + journals * 28;
	int augment = 0;

	int cm100 = 1;
	int cm99 = 1;
	int cm98 = 1;
	int t4 = 1;
	int recs = 1;
	int weekly = 1;
	int convert_pots = 1;


/* Output déclaration */


	//tier cost
	int tier_cost_t1_r = 25000, tier_cost_t1_p = 0, tier_cost_t1_m = 75, tier_cost_t1_j = 8;
	int tier_cost_t2_r = 35000, tier_cost_t2_p = 1200, tier_cost_t2_m = 150, tier_cost_t2_j = 0;
	int tier_cost_t3_r = 45000, tier_cost_t3_p = 0, tier_cost_t3_m = 225, tier_cost_t3_j = 16;
	int tier_cost_t4_r = 55000, tier_cost_t4_p = 2000, tier_cost_t4_m = 300, tier_cost_t4_j = 0;


	//total tier cost
	int total_cost_t1_r = tier_cost_t1_r, total_cost_t1_p = tier_cost_t1_p, total_cost_t1_m = tier_cost_t1_m, total_cost_t1_j = tier_cost_t1_j;
	int total_cost_t2_r = total_cost_t1_r + tier_cost_t2_r, total_cost_t2_p = total_cost_t1_p + tier_cost_t2_p, total_cost_t2_m = total_cost_t1_m + tier_cost_t2_m, total_cost_t2_j = total_cost_t1_j + tier_cost_t2_j;
	int total_cost_t3_r = total_cost_t2_r + tier_cost_t3_r, total_cost_t3_p = total_cost_t2_p + tier_cost_t3_p, total_cost_t3_m = total_cost_t2_m + tier_cost_t3_m, total_cost_t3_j = total_cost_t2_j + tier_cost_t3_j;
	int total_cost_t4_r = total_cost_t3_r + tier_cost_t4_r, total_cost_t4_p = total_cost_t3_p + tier_cost_t4_p, total_cost_t4_m = total_cost_t3_m + tier_cost_t4_m, total_cost_t4_j = total_cost_t3_j + tier_cost_t4_j;


	//Gain by day

	int relics_by_day = (cm100 * (139+ augment * 5)) + (cm99 * (159 + augment * 5)) + (cm98 * (159 + augment * 5)) + (t4 * (54 + augment * 15)) + (recs * (34 + augment * 11)) + (weekly * 7) + convert_pots * 48;
	int pristines_by_day = cm100 * 2 + cm99 * 2 + cm98 * 2 + t4 * 12 + recs * 3;
	int matrix_by_day = cm100 * 1 + cm99 * 1 + cm98 * 1;
	float pages_by_day = cm100 * 1 + cm99 * 1 + cm98 * 1 + recs * 3 + weekly * 0.285714285714285;


	//normal duration
	int norm_dura_t1_r, norm_dura_t1_p, norm_dura_t1_m, norm_dura_t1_j = 0;
	int norm_dura_t2_r, norm_dura_t2_p, norm_dura_t2_m, norm_dura_t2_j = 0;
	int norm_dura_t3_r, norm_dura_t3_p, norm_dura_t3_m, norm_dura_t3_j = 0;
	int norm_dura_t4_r, norm_dura_t4_p, norm_dura_t4_m, norm_dura_t4_j = 0;


	//ideal conversions
	int p_to_r_t1 = 0, r_to_m_t1 = 0;
	int p_to_r_t2 = 0, r_to_m_t2 = 0;
	int p_to_r_t3 = 0, r_to_m_t3 = 0;
	int p_to_r_t4 = 0, r_to_m_t4 = 0;


	//ideal duration
	int t1_time = 0;
	int t2_time = 0;
	int t3_time = 0;
	int t4_time = 0;


/* calcul déclaration */

	//gain des augmentation de chaque tier (r)
	int augment_by_day_t1 = 1 * (cm100 * 5 + cm99 * 5 + cm98 * 5 + t4 * 15 + recs * 11);
	int augment_by_day_t2 = 2 * (cm100 * 5 + cm99 * 5 + cm98 * 5 + t4 * 15 + recs * 11);
	int augment_by_day_t3 = 3 * (cm100 * 5 + cm99 * 5 + cm98 * 5 + t4 * 15 + recs * 11);
	int augment_by_day = augment * (cm100 * 5 + cm99 * 5 + cm98 * 5 + t4 * 15 + recs * 11);
	int augment_base_gain = cm100 * 5 + cm99 * 5 + cm98 * 5 + t4 * 15 + recs * 11;

	//relics par jour
	int gain_r = relics_by_day - augment_by_day;


	//coup des tier (les journal sont en pages)
	int t1_r = tier_cost_t1_r, t2_r = tier_cost_t2_r, t3_r = tier_cost_t3_r, t4_r = tier_cost_t4_r;
	int t1_p = tier_cost_t1_p, t2_p = tier_cost_t2_p, t3_p = tier_cost_t3_p, t4_p = tier_cost_t4_p;
	int t1_m = tier_cost_t1_m, t2_m = tier_cost_t2_m, t3_m = tier_cost_t3_m, t4_m = tier_cost_t4_m;
	int t1_j = tier_cost_t1_j * 28, t2_j = tier_cost_t2_j * 28, t3_j = tier_cost_t3_j * 28, t4_j = tier_cost_t4_j * 28;

	//relics que l'on a déjà et les reste a l'achat
	int reste_r = relics;
	int reste_p = pristines;
	int reste_m = matrix;
	int reste_j = pages;

	//normal duration pour affichage
	norm_dura_t1_r = tier_cost_t1_r / relics_by_day, norm_dura_t1_p = tier_cost_t1_p / pristines_by_day, norm_dura_t1_m = tier_cost_t1_m / matrix_by_day, norm_dura_t1_j = tier_cost_t1_j / pages_by_day;
	norm_dura_t2_r = tier_cost_t2_r / relics_by_day, norm_dura_t2_p = tier_cost_t2_p / pristines_by_day, norm_dura_t2_m = tier_cost_t2_m / matrix_by_day, norm_dura_t2_j = tier_cost_t2_j / pages_by_day;
	norm_dura_t3_r = tier_cost_t3_r / relics_by_day, norm_dura_t3_p = tier_cost_t3_p / pristines_by_day, norm_dura_t3_m = tier_cost_t3_m / matrix_by_day, norm_dura_t3_j = tier_cost_t3_j / pages_by_day;
	norm_dura_t4_r = tier_cost_t4_r / relics_by_day, norm_dura_t4_p = tier_cost_t4_p / pristines_by_day, norm_dura_t4_m = tier_cost_t4_m / matrix_by_day, norm_dura_t4_j = tier_cost_t4_j / pages_by_day;



	//augmentation déjà acheter
	if(augment == 1) {
		t1_r = 0;
		t1_p = 0;
		t1_m = 0;
		t1_j = 0;
		norm_dura_t1_r = 0, norm_dura_t1_p = 0, norm_dura_t1_m = 0, norm_dura_t1_j = 0;
	}
	else if(augment == 2) {
		t1_r = 0, t2_r = 0;
		t1_p = 0, t2_p = 0;
		t1_m = 0, t2_m = 0;
		t1_j = 0, t2_j = 0;
		norm_dura_t1_r = 0, norm_dura_t1_p = 0, norm_dura_t1_m = 0, norm_dura_t1_j = 0;
		norm_dura_t2_r = 0, norm_dura_t2_p = 0, norm_dura_t2_m = 0, norm_dura_t2_j = 0;
	}
	else if(augment == 3) {
		t1_r = 0, t2_r = 0, t3_r = 0;
		t1_p = 0, t2_p = 0, t3_p = 0;
		t1_m = 0, t2_m = 0, t3_m = 0;
		t1_j = 0, t2_j = 0, t3_j = 0;
		norm_dura_t1_r = 0, norm_dura_t1_p = 0, norm_dura_t1_m = 0, norm_dura_t1_j = 0;
		norm_dura_t2_r = 0, norm_dura_t2_p = 0, norm_dura_t2_m = 0, norm_dura_t2_j = 0;
		norm_dura_t3_r = 0, norm_dura_t3_p = 0, norm_dura_t3_m = 0, norm_dura_t3_j = 0;
	}
	else if(augment == 4) {
		t1_r, t2_r, t3_r, t4_r = 0;
		t1_p, t2_p, t3_p, t4_p = 0;
		t1_m, t2_m, t3_m, t4_m = 0;
		t1_j, t2_j, t3_j, t4_j = 0;
		norm_dura_t1_r = 0, norm_dura_t1_p = 0, norm_dura_t1_m = 0, norm_dura_t1_j = 0;
		norm_dura_t2_r = 0, norm_dura_t2_p = 0, norm_dura_t2_m = 0, norm_dura_t2_j = 0;
		norm_dura_t3_r = 0, norm_dura_t3_p = 0, norm_dura_t3_m = 0, norm_dura_t3_j = 0;
		norm_dura_t4_r = 0, norm_dura_t4_p = 0, norm_dura_t4_m = 0, norm_dura_t4_j = 0;
	}

	
	//décremente les resource que l'on posséde
	t1_r = coutMoinReste(t1_r, &reste_r);
	t1_p = coutMoinReste(t1_p, &reste_p);
	t1_m = coutMoinReste(t1_m, &reste_m);
	t1_j = coutMoinReste(t1_j, &reste_j);

	t2_r = coutMoinReste(t2_r, &reste_r);
	t2_p = coutMoinReste(t2_p, &reste_p);
	t2_m = coutMoinReste(t2_m, &reste_m);
	t2_j = coutMoinReste(t2_j, &reste_j);

	t3_r = coutMoinReste(t3_r, &reste_r);
	t3_p = coutMoinReste(t3_p, &reste_p);
	t3_m = coutMoinReste(t3_m, &reste_m);
	t3_j = coutMoinReste(t3_j, &reste_j);

	t4_r = coutMoinReste(t4_r, &reste_r);
	t4_p = coutMoinReste(t4_p, &reste_p);
	t4_m = coutMoinReste(t4_m, &reste_m);
	t4_j = coutMoinReste(t4_j, &reste_j);





	/* Calcul */
		

	
	
	int p_to_r_time_overload_t4 = 0, p_to_r_time_overload_t3 = 0, p_to_r_time_overload_t2 = 0, p_to_r_time_overload_t1 = 0;
	int p_time_overload_t4 = 0, p_time_overload_t3 = 0, p_time_overload_t2 = 0;
	

/*--------------------------------------------------------------------Si m > r--------------------------------------------------------------------------*/


	// Si time m > time r ## si oui m time - r time = r time overload ## si non r time overload = 0

	//réajuste les coup des tier pour que ça prenne en compte les m time overload des tier
	/*
		cout | time
	180  | 60
	     | 50

	180 - x = reste * 15
	*/
	
	m_to_r(&t4_r, &t4_m, gain_r, augment_by_day_t3, matrix_by_day, &r_to_m_t4);
	m_to_r(&t3_r, &t3_m, gain_r, augment_by_day_t2, matrix_by_day, &r_to_m_t3);
	m_to_r(&t2_r, &t2_m, gain_r, augment_by_day_t1, matrix_by_day, &r_to_m_t2);
	m_to_r(&t1_r, &t1_m, gain_r, 0, matrix_by_day, &r_to_m_t1);
	

/*--------------------------------------------------------------------Si p > r--------------------------------------------------------------------------*/

	if(augment != 3 && augment != 4) {
	// regarde si r time < p time ## si oui r time - p time = p time overload ## si non p time overload = 0
		if(t4_r / (gain_r + augment_by_day_t3) < t4_p / pristines_by_day && augment < 3) {
			p_time_overload_t4 = t4_p / pristines_by_day - t4_r / (gain_r + augment_by_day_t3);
		}
		else {
			p_time_overload_t4 = 0;
		}

		//réajuste les coup des tier pour que ça prenne en compte les p time overload des tier
		t4_p -= p_time_overload_t4 * pristines_by_day;
		t3_p += p_time_overload_t4 * pristines_by_day;

		if(augment != 2) {

			//#
			if(t3_r / (gain_r + augment_by_day_t2) < t3_p / pristines_by_day && augment < 2) {
				p_time_overload_t3 = t3_p / pristines_by_day - t3_r / (gain_r + augment_by_day_t2);
			}
			else {
				p_time_overload_t3 = 0;
			}

			//##
			t3_p -= p_time_overload_t3 * pristines_by_day;
			t2_p += p_time_overload_t3 * pristines_by_day;

			if(augment != 1) {



				//#
				if(t2_r / (gain_r + augment_by_day_t1) < t2_p / pristines_by_day && augment < 1) {
					p_time_overload_t2 = t2_p / pristines_by_day - t2_r / (gain_r + augment_by_day_t1);
				}
				else {
					p_time_overload_t4 = 0;
				}

				//##
				t2_p -= p_time_overload_t2 * pristines_by_day;
				t1_p += p_time_overload_t2 * pristines_by_day;
			}
		}
	}


/*--------------------------------------------------------------------Si r > p--------------------------------------------------------------------------*/




	//regarde si p time < r time
	//gain de r pend le gain des p = t1_r - (gain_r * t1_p / pristines_by_day)   #####
	//p_to_r_time_overload = (gain de r pend le gain des p) / (gain_r + pristines_by_day * 15)
	//faut trouvé le temps q'il reste avec le gain des relic est de pristine

	if(t1_p / pristines_by_day < t1_r / gain_r) { //&& t1_p != 0
		p_to_r_time_overload_t1 = t1_r - (gain_r * t1_p / pristines_by_day);
		p_to_r_time_overload_t1 = p_to_r_time_overload_t1 / (gain_r + pristines_by_day * 15);
	}
	else {
		p_to_r_time_overload_t1 = 0;
	}


	reste_r += p_to_r_time_overload_t1 * pristines_by_day * 15;
	p_to_r_t1 = p_to_r_time_overload_t1 * pristines_by_day;
	t1_r = coutMoinReste(t1_r, &reste_r);
	t1_p += p_to_r_t1;




	//#
	if(t2_p / pristines_by_day < t2_r / gain_r) { //&& t2_p != 0
		p_to_r_time_overload_t2 = t2_r - (gain_r * t2_p / pristines_by_day);
		p_to_r_time_overload_t2 = p_to_r_time_overload_t2 / (gain_r + pristines_by_day * 15 + augment_by_day_t1);
	}
	else {
		p_to_r_time_overload_t2 = 0;
	}

	//##
	reste_r += p_to_r_time_overload_t2 * pristines_by_day * 15;
	p_to_r_t2 = p_to_r_time_overload_t2 * pristines_by_day;
	t2_r = coutMoinReste(t2_r, &reste_r);
	t2_p += p_to_r_t2;


	//#
	if(t3_p / pristines_by_day < t3_r / gain_r) { //&& t3_p != 0
		p_to_r_time_overload_t3 = t3_r - (gain_r * t3_p / pristines_by_day);
		p_to_r_time_overload_t3 = p_to_r_time_overload_t3 / (gain_r + pristines_by_day * 15 + augment_by_day_t2);
	}
	else {
		p_to_r_time_overload_t3 = 0;
	}

	//##
	reste_r += p_to_r_time_overload_t3 * pristines_by_day * 15;
	p_to_r_t3 = p_to_r_time_overload_t3 * pristines_by_day;
	t3_r = coutMoinReste(t3_r, &reste_r);
	t3_p += p_to_r_t3;

	//#
	if(t4_p / pristines_by_day < t4_r / gain_r) { //&& t4_p != 0
		p_to_r_time_overload_t4 = t4_r - (gain_r * t4_p / pristines_by_day);
		p_to_r_time_overload_t4 = p_to_r_time_overload_t4 / (gain_r + pristines_by_day * 15 + augment_by_day_t3);
	}
	else {
		p_to_r_time_overload_t4 = 0;
	}

	//##
	reste_r += p_to_r_time_overload_t4 * pristines_by_day * 15;
	p_to_r_t4 = p_to_r_time_overload_t4 * pristines_by_day;
	t4_r = coutMoinReste(t4_r, &reste_r);
	t4_p += p_to_r_t4;


/*--------------------------------------------------------------------Si m > r--------------------------------------------------------------------------*/


	// Si time m > time r ## si oui m time - r time = r time overload ## si non r time overload = 0

	//réajuste les coup des tier pour que ça prenne en compte les m time overload des tier
	/*
		cout | time
	180  | 60
	     | 50

	180 - x = reste * 15
	*/
	
	m_to_r(&t4_r, &t4_m, gain_r, augment_by_day_t3, matrix_by_day, &r_to_m_t4);
	m_to_r(&t3_r, &t3_m, gain_r, augment_by_day_t2, matrix_by_day, &r_to_m_t3);
	m_to_r(&t2_r, &t2_m, gain_r, augment_by_day_t1, matrix_by_day, &r_to_m_t2);
	m_to_r(&t1_r, &t1_m, gain_r, 0, matrix_by_day, &r_to_m_t1);


/*-----------------------------------------------------------------calcul des reste---------------------------------------------------------------------*/

	// regade le reste des tier a l'achat et les met dans les tier au dessu !!

	//sort le time du tier ## atualise les reste avec les reste d'achat du tier
	int norm_dura_t1 = timeMiniTier(t1_r, t1_p, t1_m, t1_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 1);
	resteAppreAchat(norm_dura_t1, t1_r, t1_p, t1_m, t1_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 1, &reste_r, &reste_p, &reste_m, &reste_j);
	//décremente les resource que l'on a en trop


	
	t2_r = coutMoinReste(t2_r, &reste_r);
	t2_p = coutMoinReste(t2_p, &reste_p);
	t2_m = coutMoinReste(t2_m, &reste_m);
	t2_j = coutMoinReste(t2_j, &reste_j);


	//#
	int norm_dura_t2 = timeMiniTier(t2_r, t2_p, t2_m, t2_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 2);
	resteAppreAchat(norm_dura_t2, t2_r, t2_p, t2_m, t2_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 2, &reste_r, &reste_p, &reste_m, &reste_j);
	
	//##
	t3_r = coutMoinReste(t3_r, &reste_r);
	t3_p = coutMoinReste(t3_p, &reste_p);
	t3_m = coutMoinReste(t3_m, &reste_m);
	t3_j = coutMoinReste(t3_j, &reste_j);

	//#
	int norm_dura_t3 = timeMiniTier(t3_r, t3_p, t3_m, t3_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 3);
	resteAppreAchat(norm_dura_t3, t3_r, t3_p, t3_m, t3_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 3, &reste_r, &reste_p, &reste_m, &reste_j);
	
	//##
	t4_r = coutMoinReste(t4_r, &reste_r);
	t4_p = coutMoinReste(t4_p, &reste_p);
	t4_m = coutMoinReste(t4_m, &reste_m);
	t4_j = coutMoinReste(t4_j, &reste_j);

	int norm_dura_t4 = timeMiniTier(t4_r, t4_p, t4_m, t4_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 4);


/*-------------------------------------------------------------------final time-------------------------------------------------------------------------*/

	
	t1_time = timeMiniTier(t1_r, t1_p, t1_m, t1_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 1);
	t2_time = timeMiniTier(t2_r, t2_p, t2_m, t2_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 2) + t1_time;
	t3_time = timeMiniTier(t3_r, t3_p, t3_m, t3_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 3) + t2_time;
	t4_time = timeMiniTier(t4_r, t4_p, t4_m, t4_j, gain_r, pristines_by_day, matrix_by_day, pages_by_day, augment_base_gain, 4) + t3_time;


	printf("\n\nTime : \n");
	printf("t1 : %d\nP to R : %d\nM buy : %d\n\n", t1_time, p_to_r_t1, r_to_m_t1);
	printf("t2 : %d\nP to R : %d\nM buy : %d\n\n", t2_time, p_to_r_t2, r_to_m_t2);
	printf("t3 : %d\nP to R : %d\nM buy : %d\n\n", t3_time, p_to_r_t3, r_to_m_t3);
	printf("t4 : %d\nP to R : %d\nM buy : %d\n\n", t4_time, p_to_r_t4, r_to_m_t4);



	return 0;
}


void resteAppreAchat(int norm_dura_t, int t_r, int t_p, int t_m, int t_j, int gain_r, int pristines_by_day, int matrix_by_day, int pages_by_day, int augment_base_gain, int tier, int *reste_r, int *reste_p, int *reste_m, int *reste_j) {

	if(norm_dura_t > t_r / (gain_r + augment_base_gain * tier)) {
		*reste_r += (gain_r + augment_base_gain * tier) * (norm_dura_t - t_r / (gain_r + augment_base_gain * tier));
	}

	if(norm_dura_t > t_p / pristines_by_day) {
		*reste_p += pristines_by_day * (norm_dura_t - t_p / pristines_by_day);
	}


	if(norm_dura_t > t_m / matrix_by_day)	{
		*reste_m += matrix_by_day * (norm_dura_t - t_m / matrix_by_day);
	}
	

	if(norm_dura_t > t_j / pages_by_day) {
		*reste_j += pages_by_day* (norm_dura_t - t_j / pages_by_day);
	}
}

int timeMiniTier(int t_r, int t_p, int t_m, int t_j, int gain_r, int pristines_by_day, int matrix_by_day, float pages_by_day, int augment_base_gain, int tier) {

	int norm_dura_t = 0;

	if(t_r / gain_r > t_p / pristines_by_day) {
		norm_dura_t = t_r / (gain_r + tier * augment_base_gain);
	}
	else {
		norm_dura_t = t_p / pristines_by_day;
	}

	if(norm_dura_t < t_m / matrix_by_day) {
		norm_dura_t = t_m / matrix_by_day;
	}
	
	if(norm_dura_t < t_j / pages_by_day) {
		norm_dura_t = t_j / pages_by_day;
	}

	return norm_dura_t;
}

int coutMoinReste(int t_r, int *reste) {

	int x = t_r - *reste;

	if(x <= 0) {
		*reste -= t_r;
		t_r = 0;
	}
	else {
		t_r -= *reste;
		*reste = 0;
	}
	return t_r;
}

void m_to_r(int *t_r, int *t_m, int gain_r, int augment, int matrix_by_day, int *r_to_m_t) {
	int r_time_overload_t = 0;
	if(*t_r / (gain_r + augment) < *t_m / matrix_by_day) {
		r_time_overload_t = *t_m / matrix_by_day - *t_r / (gain_r + augment);
	}
	else {
		r_time_overload_t = 0;
	}

	if(t_m != 0) {
		*r_to_m_t += (*t_m * r_time_overload_t) / (*t_m / matrix_by_day);
		*t_r += (*t_m * r_time_overload_t) / (*t_m / matrix_by_day) * 15;
		*t_m -= *r_to_m_t;
	}
}
