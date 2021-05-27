import cv2 as cv
import sys

class Convert:
    def __init__(self, img):
        self.image = cv.imread(img)
        self.image = cv.transpose(self.image)
        self.width = self.image.shape[0]
        self.heigth = self.image.shape[1]

        self.size = (self.width, self.heigth)
        self.font_size = 12

        self.strlist = " .,;|>?*+=%&$#A@"


    def save_picture_txt(self):
        gray_image = cv.cvtColor(self.image,cv.COLOR_BGR2GRAY)
        new_color = (gray_image // 17)
        font_step = int(self.font_size * 0.6)
        with open('hospital.txt', 'w') as file:
            file.write(str(int(self.heigth / font_step)) + '\n')
            for row in range(0,self.width,font_step):
                for colown in range(0,self.heigth,font_step):
                    file.write(str(self.strlist[new_color[colown][row]]))
                file.write('\n')

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Error")
        sys.exit();

    cnv = Convert(sys.argv[1])
    cnv.save_picture_txt()
