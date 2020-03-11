import numpy as np
import time

from ccp_ext import CppLib
from pylib import py_calculate_cost, numba_calculate_cost

lib = CppLib()

cp_func = lambda m1, m2: lib.calculate_cost(m1, m2)
py_func = lambda m1, m2: py_calculate_cost(m1, m2)
nb_func = lambda m1, m2: numba_calculate_cost(m1, m2)

np.random.seed(0)
# Demand And Production
dim = (10000,100)
dmnd_mat = 195000 * np.random.randint(low=0, high=3, size=dim).astype(float)
prod_mat = 195000 * np.random.randint(low=0, high=3, size=dim).astype(float)
prod_noise = np.random.randint(low=-5000, high=5000, size=dim).astype(float)
prod_mat[prod_mat > 0] += prod_noise[prod_mat > 0]

print('Demand:')
print(dmnd_mat)
print('-'*30)
print('Production')
print(prod_mat)
print('-'*30)

n_trials = 100
#Python Implementation
py_times = []
for _ in range(10):
    ini_time = time.time()
    c1 = py_func(dmnd_mat, prod_mat)
    py_times.append(time.time() - ini_time)
py_t = np.mean(py_times)
print('Python: ')
print('Speed Up %         {}%'.format(0))
print('Mean               {}'.format(np.mean(py_times)))
print('Standard Deviation {}'.format(np.std(py_times)))
print('-'*30)

#Numba Implementation
nb_times = []
for _ in range(n_trials):
    ini_time = time.time()
    c2 = nb_func(dmnd_mat, prod_mat)
    nb_times.append(time.time() - ini_time)
nb_t = np.mean(nb_times)
print('Numba: ')
print('Speed Up %         {}%'.format((py_t/nb_t-1)*100))
print('Mean               {}'.format(np.mean(nb_times)))
print('Standard Deviation {}'.format(np.std(nb_times)))
print('-'*30)

# C++ Implementation
cpp_times = []
for _ in range(n_trials):
    ini_time = time.time()
    c3 = cp_func(dmnd_mat, prod_mat)
    cpp_times.append(time.time() - ini_time)
cp_t = np.mean(cpp_times)
print('C++: ')
print('Speed Up %         {}%'.format((py_t/cp_t-1)*100))
print('Mean               {}'.format(np.mean(cpp_times)))
print('Standard Deviation {}'.format(np.std(cpp_times)))
print('-'*30)

assert all(c1[-1] == c2[-1])
assert all(c1[-1] == c3[-1])
