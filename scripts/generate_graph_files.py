import os
import random


def create_graph_files(number_of_files:int=1, edges:int=3, vertices:int=2 ):

    os.chdir(os.path.dirname(__file__) + "/data_in")
    

    for i in range(0, number_of_files):
        

        u = random.randint(0, vertices)
        v = random.randint()
        with open(f"data{i}.txt", "w") as file:

            file.write(edges + " " + vertices)

            for j in range(0, edges):
                file.write(f"{random.}\n")


def main():
    create_graph_files(edges=1, vertices=30)


if __name__ == "__main__":
    main()