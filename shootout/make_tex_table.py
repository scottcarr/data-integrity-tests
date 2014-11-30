from subprocess import Popen, PIPE

def getUserTime(txt):
    parts = txt.split()
    user = parts[0]
    number = user.rstrip("user")
    return float(number)

benchmarks = ["binarytrees", "fasta", "nbody"]

args = ["time", "./binarytrees", "15"]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
bt_orig = getUserTime(txt)

args = ["time", "./binarytrees_dci", "15"]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
bt_dci = getUserTime(txt)

args = ["time", "./fasta", "1000000"]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
f_orig = getUserTime(txt)

args = ["time", "./fasta_dci", "1000000"]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
f_dci = getUserTime(txt)

args = ["time", "./nbody", "1000000"]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
nbody_orig = getUserTime(txt)

args = ["time", "./nbody_dci", "1000000"]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
nbody_dci = getUserTime(txt)

#print bt_orig, bt_dci, f_orig, f_dci, nbody_orig, nbody_dci

bt_ovh = bt_dci / bt_orig
f_ovh = f_dci / f_orig
nbody_ovh = nbody_dci / nbody_orig

#bt_ovh = .7
#f_ovh = .5
#nbody_ovh = .1

#print bt_ovh, f_ovh, nbody_ovh


tbl_txt = """
\\begin{{table}}
\\centering
\\begin{{tabular}}{{l | r}}
name & \% overhead \\\\
\\hline
binarytrees & {0} \\\\
fasta & {1} \\\\
nbody & {2} \\\\
\end{{tabular}}
\label{{tbl:micro}}
\caption{{Performance overhead on Computer Language Benchmarks Game}}
\end{{table}}
"""

print tbl_txt.format(bt_ovh*100-100, f_ovh*100-100, nbody_ovh*100-100)
