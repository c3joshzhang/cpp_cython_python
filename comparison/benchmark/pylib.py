import numpy as np
import numba as nb

def py_calculate_cost(dmnd_mat, prod_mat):

	def _delay_cost(quantity, hrs):
		unit_cost = 2 if hrs >= 0 else -1
		total_cost = quantity * hrs * unit_cost
		return total_cost

	cost_mat = np.zeros_like(dmnd_mat)
	n_steps, n_prods = dmnd_mat.shape
	for p in range(n_prods):
		t_dmnd, t_prod = 0, 0
		cur_d = dmnd_mat[t_dmnd, p]
		cur_p = prod_mat[t_prod, p]
		while (t_dmnd < n_steps and t_prod < n_steps):
			# demand pointer
			while(cur_d == 0):
				t_dmnd += 1
				if t_dmnd == n_steps:
					break
				cur_d = dmnd_mat[t_dmnd, p]
			# production pointer
			while (cur_p == 0):
				t_prod += 1
				if t_prod == n_steps:
					break
				cur_p = prod_mat[t_prod, p]
			# when reach the end
			if (t_dmnd == n_steps or t_prod == n_steps):
				break
			# fufill demand
			n_hrs = t_prod - t_dmnd
			filled = min(cur_p, cur_d)
			cur_d -= filled
			cur_p -= filled
			cost_mat[t_dmnd, p] += _delay_cost(filled, n_hrs)

		cost_mat[-1, p] += _delay_cost(cur_d, n_steps - t_dmnd)
		t_dmnd += 1

		while (t_dmnd < n_steps):
			cur_d = dmnd_mat[t_dmnd, p]
			cost_mat[-1, p] += _delay_cost(cur_d, n_steps - t_dmnd)
			t_dmnd += 1
	return cost_mat

@nb.jit(nopython=True)
def numba_calculate_cost(dmnd_mat, prod_mat):

	def _delay_cost(quantity, hrs):
		unit_cost = 2 if hrs >= 0 else -1
		total_cost = quantity * hrs * unit_cost
		return total_cost

	cost_mat = np.zeros_like(dmnd_mat)
	n_steps, n_prods = dmnd_mat.shape
	for p in range(n_prods):
		t_dmnd, t_prod = 0, 0
		cur_d = dmnd_mat[t_dmnd, p]
		cur_p = prod_mat[t_prod, p]
		while (t_dmnd < n_steps and t_prod < n_steps):
			# demand pointer
			while(cur_d == 0):
				t_dmnd += 1
				if t_dmnd == n_steps:
					break
				cur_d = dmnd_mat[t_dmnd, p]
			# production pointer
			while (cur_p == 0):
				t_prod += 1
				if t_prod == n_steps:
					break
				cur_p = prod_mat[t_prod, p]
			# when reach the end
			if (t_dmnd == n_steps or t_prod == n_steps):
				break
			# fufill demand
			n_hrs = t_prod - t_dmnd
			filled = min(cur_p, cur_d)
			cur_d -= filled
			cur_p -= filled
			cost_mat[t_dmnd, p] += _delay_cost(filled, n_hrs)

		cost_mat[-1, p] += _delay_cost(cur_d, n_steps - t_dmnd)
		t_dmnd += 1

		while (t_dmnd < n_steps):
			cur_d = dmnd_mat[t_dmnd, p]
			cost_mat[-1, p] += _delay_cost(cur_d, n_steps - t_dmnd)
			t_dmnd += 1
	return cost_mat
