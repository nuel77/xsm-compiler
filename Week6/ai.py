from numpy import mean
from numpy import std
from matplotlib import pyplot
# from sklearn.model_selection import KFold
from keras.datasets import mnist
from keras.models import load_model
from keras.utils import to_categorical
from keras.models import Sequential
from keras.layers import Conv2D
from keras.layers import MaxPooling2D
from keras.layers import Dense
from keras.layers import Flatten
from keras.optimizers import SGD, Adam
from keras.models import Input
from keras.layers import Dropout

 
# load train and test dataset
def load_dataset():
	# load dataset
	(trainX, trainY), (testX, testY) = mnist.load_data()
	# reshape dataset to have a single channel
	trainX = trainX.reshape((trainX.shape[0], 28, 28, 1))
	testX = testX.reshape((testX.shape[0], 28, 28, 1))
	# one hot encode target values
	trainY = to_categorical(trainY)
	testY = to_categorical(testY)
	return trainX, trainY, testX, testY

 
# scale pixels
def prep_pixels(train, test):
	# convert from integers to floats
	train_norm = train.astype('float32')
	test_norm = test.astype('float32')
	# normalize to range 0-1
	train_norm = train_norm / 255.0
	test_norm = test_norm / 255.0
	# return normalized images
	return train_norm, test_norm
 

# # define cnn model
# def define_model():
#   model = Sequential()
#   model.add(Flatten(input_shape=(28, 28, 1)))
#   model.add(Dense(128, activation='relu'))
#   model.add(Dense(10, activation='softmax'))
#  	# compile model
#   opt=Adam(lr=0.001, epsilon=1e-06)
#   model.compile(optimizer=opt, loss='categorical_crossentropy', metrics=['accuracy'])
#   return model
 
# define cnn model
def define_model():
  model = Sequential()
  model.add(Conv2D(64, (2,2), activation='relu',input_shape=(28, 28, 1)))
  model.add(MaxPooling2D((2,2)))
  model.add(Dropout(0.25))
  model.add(Conv2D(64, (2,2), activation='relu'))
  model.add(MaxPooling2D((2,2)))
  model.add(Dropout(0.25))
  model.add(Conv2D(64, (2,2), activation='relu'))
  model.add(MaxPooling2D((2,2)))
  model.add(Dropout(0.25))
  model.add(Conv2D(64, (2,2), activation='relu'))
  model.add(Dropout(0.25))
  model.add(Flatten())
  model.add(Dense(64, activation='relu'))
  model.add(Dropout(0.25))
  model.add(Dense(10, activation='softmax'))
 	# compile model
  #opt=SGD(lr=0.01, momentum=0.9)
  #opt=Adagrad(lr=0.01, epsilon=1e-06)
  #opt=RMSprop(lr=0.001, epsilon=1e-06)
  #opt=Adadelta(lr=1.0, epsilon=1e-06)
  opt=Adam(lr=0.1, epsilon=1e-06)
  model.compile(optimizer=opt, loss='categorical_crossentropy', metrics=['accuracy'])
  return model 
 
 
def run_test_harness():
	# load dataset
	trainX, trainY, testX, testY = load_dataset()
	# prepare pixel data
	trainX, testX = prep_pixels(trainX, testX)
	# define model
	model = define_model()
	# fit model
	model.fit(trainX, trainY, epochs=5, batch_size=32, verbose=0)
	# save model
	model.save('C:/Users/emman/Desktop/S6/AI/final_model.h5')
 
# entry point, run the test harness
run_test_harness()