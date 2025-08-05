def hamming(binary_string):
    print(f"hamming with: {binary_string}")
    
    # string a lista de bits 
    bits = list(binary_string)
    n = len(bits)
    
    # clculo de cantidad de bits de pariedad
    r = 0
    while 2**r < n + 1:
        r += 1
    
    # calcular el síndrome aka las posiciones erroneas
    syndrome = 0
    for p in range(r):
        pos_paridad = 2**p - 1  # base 0
        count = 0
        
        # Verificar todas las posiciones cubiertas por este bit de paridad
        for i in range(pos_paridad, n, 2**(p + 1)):
            for j in range(i, min(i + 2**p, n)):
                if bits[j] == '1':
                    count += 1
        
        # Si la paridad es impar, hay error
        if count % 2 != 0:
            syndrome += pos_paridad + 1  
    
    # Corregir error si hay
    if syndrome != 0:
        if syndrome - 1 < n:
            print(f"Error detectado en posición {syndrome}")
            bits[syndrome - 1] = '1' if bits[syndrome - 1] == '0' else '0'
        else:
            print("Error no corregible (síndrome fuera de rango)")
            return None
    
    # obtener bits de datos 
    data_bits = []
    data_index = 0
    for i in range(n):
        # Las posiciones de datos son las que no son potencias de 2
        if (i + 1) & i != 0:
            if data_index < len(binary_string) - r:
                data_bits.append(bits[i])
                data_index += 1
    result = ''.join(data_bits) 
    print(f"Cadena orignal: {result}")
    return result