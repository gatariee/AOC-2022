with open("../input.txt", "r") as f:
    data = f.read().splitlines()

def solve(data: list):
    current_sum = 0
    for i, item in enumerate(data):
        if item == "":
            remaining_data = data[i+1:]
            elf_sums = solve(remaining_data)
            return [current_sum] + elf_sums

        current_sum += int(item)

    return [current_sum]

list_of_sums = solve(data)
print(max(list_of_sums))
