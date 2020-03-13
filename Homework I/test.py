import numpy as np
import time

def insert_sort(A):
  for i in range(len(A)):
    cur_value = A[i]
    j = i -1
    while j>= 0 and A[j] > cur_value:
      A[j + 1]= A[j]
      j = j - 1
    A[j + 1] = cur_value
  return A

def merge(A, B):
  result = []
  while len(A) != 0 and len(B) != 0:
    if A[0] < B[0]:
      result.append(A[0])
      A = np.delete(A, 0)
    else:
      result.append(B[0])
      B = np.delete(B, 0)
  result.extend(A)
  result.extend(B)
  result = np.array(result)
  return result

def merge_sort(A):
  if len(A) <= 1:
    return A
  left = []
  for i in range(int(len(A)/2)):
    left.append(A[0])
    A = np.delete(A, 0)
    right = A
  return merge(merge_sort(left), merge_sort(right))

def is_sorted(a):
  for i in range(a.size - 1):
    if a[i+1] < a[i] :
      return False
    return True

def main():
  ns = np.linspace(10000, 100000, 10)

  print("Random numbers:")
  for n in ns:
    # create and fill an array with random numbers
    a = np.random.randint(0,10000, int(n)) 

    # call insert_sort and  calculate the time
    start_time = time.time()
    sorted_a = insert_sort(a)
    t1 =  (time.time() - start_time)

    if not is_sorted(sorted_a):
      print("ERROR")

    # call merge_sort and  calculate the time
    start_time = time.time()
    sorted_a = merge_sort(a)
    t2 =  (time.time() - start_time)

    if not is_sorted(sorted_a):
      print("ERROR")

    print("%d %f %f" % (n, t1, t2))

  print("Ascending order:")
  for n in ns:
    # create and fill an array in ascending order
    a = np.arange(int(n)) 

    # call insert_sort and  calculate the time
    start_time = time.time()
    sorted_a = insert_sort(a)
    t1 =  (time.time() - start_time)

    if not is_sorted(sorted_a):
      print("ERROR")

    # call merge_sort and  calculate the time
    start_time = time.time()
    sorted_a = merge_sort(a)
    t2 =  (time.time() - start_time)

    if not is_sorted(sorted_a):
      print("ERROR")

    print("%d %f %f" % (n, t1, t2))

  print("Descing order:")
  for n in ns:
    # create and fill an array in descing order
    a = np.arange(int(n)) 
    a = np.sort(a)[::-1]

    # call insert_sort and  calculate the time
    start_time = time.time()
    sorted_a = insert_sort(a)
    t1 =  (time.time() - start_time)

    if not is_sorted(sorted_a):
      print("ERROR")

    # call merge_sort and  calculate the time
    start_time = time.time()
    sorted_a = merge_sort(a)
    t2 =  (time.time() - start_time)

    if not is_sorted(sorted_a):
      print("ERROR")

    print("%d %f %f" % (n, t1, t2))
        
if __name__ == "__main__":
    main()

