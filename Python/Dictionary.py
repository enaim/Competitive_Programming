customer = {
    "name" : "Naim Elias",
    "age" : 22,
    "isVerified": True
}

print(customer)
print(customer["name"])
print(customer.get("birthdate"))
print(customer.get("birthdate","21 July 1997"))

customer["birthdate"] = "21 July 1997"
print(customer)

phone = input("Phone: ")
digit_mapping={
    "1" : "One",
    "2" : "Two",
    "3" : "Three",
    "4" : "Four"
}
output = ""
for ch in phone:
    output+=digit_mapping.get(ch,'!')+" "   # "!" is returned when ch is not found in dictionary
print(output)