#pragma once

class ServiceCost{
	public:
		ServiceCost();

		~ServiceCost();

		void allCost(
			double* dmnd_mat, 
	        double* prod_mat, 
	        double* cost_mat,
	        int n_steps, 
	        int n_prods);

	private:
		void singleCost(
	        double* dmnd_mat, 
	        double* prod_mat, 
	        double* cost_mat,
	        int n_steps, 
	        int n_prods, 
	        int cur_prod);

		double delay_cost(double quantity, int hrs);
};