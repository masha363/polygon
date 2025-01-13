import numpy as np
#новый массив
data = np.array([3, 3, 3, 4, 5, 5, 6, 7, 7, 7, 8, 9, 9])
#получаю уникальные элементы и их частоты
unique_el, el_counts = np.unique(data, return_counts=True)
#фильтрую элементы, которые встречаются больше двух раз
filtered_el = unique_el[el_counts > 2]
#нахожу сумму этих элементов
result_sum = np.sum(filtered_el)
#вывожу результат
print(result_sum)
