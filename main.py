import numpy as np
import time 
from cpplib import CppLib

ini_time = time.time()
a = np.random.randint(10,100, (10,20000000)).astype(np.float32)
print('Finish Filling Matrix: ', time.time() - ini_time)
c = CppLib(1)

ini_time = time.time()
c.apply(a)
print('Python Time Taken: ', time.time() - ini_time)
