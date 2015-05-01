from jinja2 import Template
import glob
import os

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
		print "lista dirs: ", imageDirs 

		for imageDir in imageDirs:
			imagesList = glob.glob(self.repertoirePlats + imageDir + "/" + "*.jpg")
			print "lista images: \n", imagesList
			for image in imagesList:
				imageInfoPath = image.replace(".jpg", ".txt")
				imageInfo = open(imageInfoPath).read().split("\n\n")
				self.listePlats.append(Plat(imageInfo[0], imageDir, imageInfo[1], imageInfo[2], "../workspace/" + image, imageInfo[3], imageInfo[4].split(';'), imageInfo[5].split(';')))

	def toXML(self, filePath):
		output = self.template.render(listePlats = self.listePlats)
		with open(filePath, "wb") as f:
			f.write('<?xml version="1.0" encoding="UTF-8"?>')
			f.write(output)
		print "XML created...\n"

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
output = liste.toXML("resources/plats.xml")




