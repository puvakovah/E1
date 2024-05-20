import matplotlib.pyplot as plt

filename = 'vysledky.txt'
velkost = []
prienik = []
zjednotenie = []

with open(filename, 'r') as f:
    for line in f:
        parts = line.split()
        velkost.append(int(parts[0]))
        prienik.append(float(parts[1]))
        zjednotenie.append(float(parts[2]))

plt.figure(figsize=(10, 6))

plt.plot(velkost,prienik, label='Prienik')
plt.plot(velkost, zjednotenie, label='Zjednotenie')

plt.xlabel('Velkost mnoziny')
plt.ylabel('Priemerny pocet operacii')
plt.title('Priemerny pocet operacii prieniku a zjednotenia')
plt.legend()
plt.grid(True)

plt.savefig('vysledky_plot.png')

plt.show()