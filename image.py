from imguralbum import ImgurAlbumDownloader

with open('/Users/proloknair/Dropbox/Algorithm/photos.txt') as f:
	links=f.read().splitlines()



for i in links:


	print(i)
	a=i.find("http")
	folder=i[:a-2]
	link=i[a:]
	link=link.strip()
	folder1="/Users/proloknair/Dropbox/leaked/"+folder.replace(" ", "")
	print(folder1)
	print(link)
	try:
		downloader = ImgurAlbumDownloader(link)
		print ("This albums has %d images" % downloader.num_images())
		downloader.save_images(folder1)
	except :
		continue