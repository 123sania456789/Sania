import pandas as pd
import matplotlib.pyplot as plt
from sklearn import datasets
olive=datasets.fetch_olivetti_faces()
#print(olive)
y=olive.target
x=olive.data
print(x)
print(y)
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=42)
#print(x_train)
#print(x_test)
#print(y_train)
#print(y_test)
from sklearn.naive_bayes import GaussianNB
gnb=GaussianNB()
gnb.fit(x_train,y_train)
y_pred=gnb.predict(x_test)
print(y_pred)
from sklearn.metrics import accuracy_score
accur=accuracy_score(y_test,y_pred)
print(f"Accuracy of Naive Bayes:{accur*100}%")
import matplotlib.pyplot as plt
n_samples=10
plt.figure(figsize=(50,10))
for i in range(n_samples):
  ax=plt.subplot(1,n_samples,i+1)
  ax.imshow(x_test[i].reshape(64,64),cmap='gray')
  ax.set_title(f"Predicted:{y_pred[i]}\n True:{y_test[i]}")
plt.show()
