import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    x=students[students['student_id']==101]
    print(x)
    return x.loc[:, ['name','age']]
