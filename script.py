import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys
import os
import subprocess
import itertools


algo_dict = {
    0: "PRIM",
    1: "Dijkstra",
    2: "Kruskal",
    3: "Bellman-Ford"
}

rep_dict = {
    0: "Matrix", 
    1: "List"
        }

# vertices = [10]
# density = [35]
# number_of_samples = [50]

density = [25, 50, 99]
number_of_samples = [25]


vertices = [10, 50, 100, 150, 200, 250, 300, 400]
# vertices = [10, 50, 100, 125, 150, 200, 250]



def collect_data():

    for my_args in itertools.product(
        algo_dict.keys(), rep_dict.keys(), vertices, density, number_of_samples
        ):

        print(my_args)

        run_process = subprocess.Popen(
            ["./main"] + [str(i) for i in my_args], stdout=subprocess.PIPE
        )
        
        output = run_process.stdout.read().decode("utf-8")
        

        time = float(output.split(": ")[1])
        print(time)

        my_data = {
            "Algorithm": [algo_dict[my_args[0]]],
            "Representation": [rep_dict[my_args[1]]],
            "Vertices": [my_args[2]],
            "Density": [my_args[3]],
            "Number of Samples": [my_args[4]],
            "Time": [time]
        }
        
        df = pd.DataFrame(my_data)
        
        
        if not os.path.isfile("wyniki.csv"):
            df.to_csv("wyniki.csv", index=False)
        else:
            df.to_csv("wyniki.csv", mode='a', header=False, index=False)


def generate_plot_type_1():
    
    # Iterate over each representation
    for representation in representations:
        plt.figure(figsize=(10, 6))
        plt.title(f'Funkcja t(v) dla reprezntacji {representation}')
        plt.xlabel('Ilość wierzchołków')
        plt.ylabel('Czas (ms)')
        
        # Filter the dataframe by representation
        df_rep = df[df['Representation'] == representation]
        
        # Plot lines for each algorithm and density
        for algorithm in algorithms:
            for density in densities:
                df_filtered = df_rep[(df_rep['Algorithm'] == algorithm) & (df_rep['Density'] == density)]
                if not df_filtered.empty:

                    # print(df_filtered['Vertices'].values)
                    # print(df_filtered['Time'].values)
                    
                    my_data = {
                        "Vertices": df_filtered['Vertices'].values,
                        "Time": df_filtered['Time'].values
                    }
                    data = pd.DataFrame(my_data)
                    data.to_latex(index=False)

                    with open(f"wyniki/{representation}_representation_{algorithm}.txt", "a") as file:
                        file.write(f"Algorithm: {algorithm}, Density: {density}\n")
                        file.write(data.to_latex(index=False))
                        file.write("\n\n\n")

                    
                    plt.plot(df_filtered['Vertices'].values, df_filtered['Time'].values, marker='o', label=f'{algorithm}, Density: {density}')
                    plt.legend()
                    plt.savefig(f"wyniki/{representation}_representation_{algorithm}.png")
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.show()


def generate_plot_type_2():
   
    # Iterate over each density for typ2
    for density in densities:
        plt.figure(figsize=(10, 6))
        plt.title(f'Funkcja t(v) dla gęstości {density}')
        plt.xlabel('Ilość wierzchołków')
        plt.ylabel('Czas (ms)')

        # Filter the dataframe by density
        df_density = df[df['Density'] == density]
        
        # Plot lines for each algorithm and representation
        for algorithm in algorithms:
            for representation in representations:
                df_filtered = df_density[(df_density['Algorithm'] == algorithm) & (df_density['Representation'] == representation)]
                if not df_filtered.empty:


                    my_data = {
                        "Vertices": df_filtered['Vertices'].values,
                        "Time": df_filtered['Time'].values
                    }
                    data = pd.DataFrame(my_data)
                    data.to_latex(index=False)

                    with open(f"wyniki/Typ2_density_{density}_MST.txt", "a") as file:
                        file.write(f"Algorithm: {algorithm}, Representation: {representation}\n")
                        file.write(data.to_latex(index=False))
                        file.write("\n\n\n")


                    plt.plot(df_filtered['Vertices'].values, df_filtered['Time'].values, marker='o', label=f'{algorithm}, {representation}')
                    plt.legend()
                    plt.savefig(f"wyniki/Typ2_density_{density}_SHORT.png")
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.show()
        

df = pd.read_csv("wyniki.csv")
    
# List of unique representations
representations = df['Representation'].unique()

# List of unique algorithms
algorithms = df['Algorithm'].unique()
algorithms = ['Bellman-Ford', 'Dijkstra']
# algorithms = ['PRIM', 'Kruskal']

# List of unique densities
densities = df['Density'].unique()



# collect_data()
# generate_plot_type_1()
generate_plot_type_2()