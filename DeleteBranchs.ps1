# Obtener lista de ramas locales
$branches = (git branch --merged).Trim()

#Validar si existen ramas
if ($branches) {
    # Mostrar lista de ramas que serán eliminadas en una ventana emergente
    $branchesToDelete = $branches | Out-GridView -Title "Selecciona las ramas a eliminar" -PassThru

    # Eliminar ramas remotas seleccionadas
    foreach ($branch in $branchesToDelete) {
	#condicional para no eliminar ramas master y release
        if($branch -ne "* master" -and $branch -ne "release"){
            git push origin --delete $branch
            Write-Host "Rama remota $branch eliminada"
        }else{
            Write-Host "No es posible eliminar la rama $branch"
        }
    }

    # Eliminar ramas locales seleccionadas
    foreach ($branch in $branchesToDelete) {
        #condicional para no eliminar ramas master y release
        if($branch -ne "* master" -and $branch -ne "release"){
            git branch -D $branch
            Write-Host "Rama local $branch eliminada"
        }else{
            Write-Host "No es posible eliminar la rama $branch"
        }
    }
}else{
    Write-Host "No hay ramas para eliminar"
}
