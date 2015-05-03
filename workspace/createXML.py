#!/usr/bin/python
# -*- coding: utf-8 -*-

from jinja2 import Template
import glob
import os

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

class ListePlats:
	def __init__(self, repertoirePlats):
		self.listePlats = []
		self.repertoirePlats = repertoirePlats
		self.template = Template("""
<lesPlats>
	{% for plat in listePlats %} 
	<plat>
		<name>{{plat.name}}</name>
		<type>{{plat.typePlat}}</type>
		<description>{{plat.description}}</description>
		<shortDescription>{{plat.shortDescription}}</shortDescription>
		<imagePath>{{plat.imagePath}}</imagePath>
		<price>{{plat.price}}</price>
		<ingredientsList>
			{% for item in plat.ingredients %} <ingredient>{{item}}</ingredient> {% endfor %}
		</ingredientsList>
		<possibleAllergiesList>
			{% for allergy in plat.possibleAllergies %} <possibleAllergie>{{allergy}}</possibleAllergie> {% endfor %}
		</possibleAllergiesList>
	</plat>
	{% endfor %}
</lesPlats>
""")
		self.chargeListe()

	def chargeListe(self):
		imageDirs = []
		for dirname, dirnames, filenames in os.walk(self.repertoirePlats):
			for dir in dirnames:
				imageDirs.append(dir)
		#print "liste dirs: ", imageDirs 

		for imageDir in imageDirs:
			imagesList = glob.glob(self.repertoirePlats + imageDir + "/" + "*.jpg")
			#print "liste images: \n", imagesList
			for image in imagesList:
				imageInfoPath = image.replace(".jpg", ".txt")
				imageInfo = open(imageInfoPath).read().split("\n\n")
				self.listePlats.append(Plat(imageInfo[0], imageDir, imageInfo[1], imageInfo[2], "../workspace/" + image, imageInfo[3], imageInfo[4].split(';'), imageInfo[5].split(';')))

	def writeXMLtoFile(self, filePath, output):
		with open(filePath, "wb") as f:
			f.write('<?xml version="1.0" encoding="UTF-8"?>')
			f.write(output)
		print "XML", filePath, "created...\n"


	"""create Plats Database XML file"""
	def platsToXML(self, filePath):
		output = self.template.render(listePlats = self.listePlats)
		self.writeXMLtoFile(filePath, output)

	def ingredientsToXML(self, filePath):
		listeIngredients = set([ingredient for plat in self.listePlats for ingredient in plat.ingredients])
		ingredientsTemplate = Template("""
<lesIngredients>
	{% for ingredient in listeIngredients %} 
    <name>{{ingredient}}</name>
   	{% endfor %}
</lesIngredients>			
""")	
		output = ingredientsTemplate.render(listeIngredients = listeIngredients)
		self.writeXMLtoFile(filePath, output)

	def allergiesToXML(self, filePath):
		listeAllergies = set([allergy for plat in self.listePlats for allergy in plat.possibleAllergies])
		allergiesTemplate = Template("""
<lesAllergies>
	{% for allergy in listeAllergies %} 
    <name>{{allergy}}</name>
   	{% endfor %}
</lesAllergies>			
""")	
		output = allergiesTemplate.render(listeAllergies = listeAllergies)
		self.writeXMLtoFile(filePath, output)

	def createXMLDatabase(self):
		self.platsToXML("resources/plats.xml")
		self.ingredientsToXML("resources/ingredients.xml")
		self.allergiesToXML("resources/allergies.xml")

class Plat:
	def __init__(self, name, typePlat, description, shortDescription, imagePath, price, ingredients, possibleAllergies):
		self.name = name
		self.typePlat = typePlat
		self.description = description
		self.shortDescription = shortDescription
		self.imagePath = imagePath
		self.price = price
		self.ingredients = ingredients
		self.possibleAllergies = possibleAllergies

liste = ListePlats("resources/imagesPlats/")
liste.createXMLDatabase()



