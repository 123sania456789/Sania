import pandas as pd
import matplotlib.pyplot as plt
from sklearn import datasets
b=datasets.load_breast_cancer()
#print(olive)
y=b.target
x=b.data
#print(x)
#print(y)
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=42)
#print(x_train)
#print(x_test)
#print(y_train)
#print(y_test)
from sklearn.tree import DecisionTreeClassifier
dtclf=DecisionTreeClassifier(criterion='entropy',random_state=42)
dtclf.fit(x_train,y_train)
y_pred=dtclf.predict(x_test)
#print(y_pred)
from sklearn.metrics import accuracy_score
accur=accuracy_score(y_test,y_pred)
print(f"Accuracy of Naive Bayes:{accur*100}%")
from sklearn import tree
plt.figure(figsize=(50,20))
tree.plot_tree(dtclf,filled=True,feature_names=b.feature_names)
plt.title('Decision Tree')
plt.show()
