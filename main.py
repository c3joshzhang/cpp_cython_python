import numpy as np
import time 
from rect import PyRectangle

ini_time = time.time()
a = np.random.randint(10,100, (10,20000000))
print('Finish Filling Matrix: ', time.time() - ini_time)
r = PyRectangle(1,2,3,4)

ini_time = time.time()
r.modify(a)
print('Python Time Taken: ', time.time() - ini_time)
