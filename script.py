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
}

rep_dict = {
    0: "Matrix", 
    1: "List"
        }

# vertices = [10]
# density = [35]
# number_of_samples = [50]

vertices = [10, 50, 100, 125, 150, 200, 250]
density = [25, 50, 99]
number_of_samples = [50]


# vertices = [10, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500]



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
    df = pd.read_csv("wyniki.csv")
    
    # List of unique representations
    representations = df['Representation'].unique()
    
    # List of unique algorithms
    algorithms = df['Algorithm'].unique()
    
    # List of unique densities
    densities = df['Density'].unique()

    # Iterate over each representation
    for representation in representations:
        plt.figure(figsize=(10, 6))
        plt.title(f'Time vs Vertices for {representation} Representation')
        plt.xlabel('Time (ms)')
        plt.ylabel('Number of Vertices')
        
        # Filter the dataframe by representation
        df_rep = df[df['Representation'] == representation]
        
        # Plot lines for each algorithm and density
        for algorithm in algorithms:
            for density in densities:
                df_filtered = df_rep[(df_rep['Algorithm'] == algorithm) & (df_rep['Density'] == density)]
                if not df_filtered.empty:
                    plt.plot(df_filtered['Time'].values, df_filtered['Vertices'].values, marker='o', label=f'{algorithm}, Density: {density}')
        
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.show()


def generate_plot_type_2():
    df = pd.read_csv("wyniki.csv")
    
    # List of unique representations
    representations = df['Representation'].unique()
    
    # List of unique algorithms
    algorithms = df['Algorithm'].unique()
    
    # List of unique densities
    densities = df['Density'].unique()

    # Iterate over each density for typ2
    for density in densities:
        plt.figure(figsize=(10, 6))
        plt.title(f'Time vs Vertices for Density {density} (Typ2)')
        plt.xlabel('Number of Vertices')
        plt.ylabel('Time (ms)')
        
        # Filter the dataframe by density
        df_density = df[df['Density'] == density]
        
        # Plot lines for each algorithm and representation
        for algorithm in algorithms:
            for representation in representations:
                df_filtered = df_density[(df_density['Algorithm'] == algorithm) & (df_density['Representation'] == representation)]
                if not df_filtered.empty:
                    plt.plot(df_filtered['Vertices'].values, df_filtered['Time'].values, marker='o', label=f'{algorithm}, {representation}')
        
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.show()

# collect_data()

generate_plot_type_1()
# generate_plot_type_2()