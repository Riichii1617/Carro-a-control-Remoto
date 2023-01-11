# Obtener lista de ramas locales
$branches = (git branch --merged | Where-Object { $_ -notlike "*" } | Where-Object { $_ -notlike "master" } | Where-Object { $_ -notlike "develop" }).Trim()

#Validar si existen ramas
if ($branches) {
    # Mostrar lista de ramas que serán eliminadas en una ventana emergente
    $branchesToDelete = $branches | Out-GridView -Title "Selecciona las ramas a eliminar" -PassThru

    # Eliminar ramas seleccionadas
    foreach ($branch in $branchesToDelete) {
        git branch -D $branch
    }

    Write-Host "Ramas eliminadas correctamente"
}else{
    Write-Host "No hay ramas para eliminar"
}
