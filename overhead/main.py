import time
import numpy as np
from cpplib import CppLib

lib = CppLib(1)

ini_time = time.time()
a = np.random.randint(10,100, (10,20000000)).astype(float)
print('Finish Filling Matrix: ', time.time() - ini_time)

ini_time = time.time()
lib.apply(a)
print('Python Time Taken: ', time.time() - ini_time)
