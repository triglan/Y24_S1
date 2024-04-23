chars = ("-", "_", ".")


def solution(new_id):
    # 1단계
    new_id = new_id.lower()

    # 2단계
    i = 0
    while i < len(new_id):
        if not new_id[i].isalpha() and not new_id[i].isdigit() and new_id[i] not in chars:
            new_id = new_id[:i] + new_id[i + 1:]
        else:
            i += 1

    # 3단계
    while ".." in new_id:
        new_id = new_id.replace("..", ".")

    # 4단계
    if new_id and new_id[0] == ".":
        new_id = new_id[1:]
    if new_id and new_id[-1] == ".":
        new_id = new_id[:-1]

    # 5단계
    if not new_id:
        new_id = "a"

    # 6단계
    if len(new_id) >= 16:
        new_id = new_id[:15]
    if new_id[-1] == ".":
        new_id = new_id[:-1]

    # 7단계
    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]

    return new_id