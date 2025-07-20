# 🛠️ Team 13 Participation and Activity Report

## 🔍 Focus: Coding Contributions to the Project Repository

This document outlines **actual contributions made to the codebase** of the `MedicationManager` project by Team 13 members. The purpose is to provide a transparent, data-driven summary of participation regarding the **backbone of the project — the code**. No assumptions or extrapolations are made beyond the verifiable commit and PR history.

---

## ⚠️ Key Observation: Minimal Participation by Most Team Members

Despite repeated emphasis on collaborative development and shared responsibility, the contribution data reveals **a clear lack of coding involvement** from most members of Team 13. Only two members contributed code at all during the past 4 months.

---

## 📊 Contribution Summary (Merged PRs + Direct Commits to `main` Branch)

```
Melissa Gandy - 98 commits, first: 2025-05-26, last: 2025-07-19  
Jonah Buckley - 20 commits, first: 2025-06-11, last: 2025-07-03  
Jeremie Bashala - no data  
Daniel Kelly - no data  
Eric Bush - no data  
```

> This shows that **three out of five team members made no visible contributions to the repository** as defined by pull requests or direct commits to the main development branch.

---

## 🔧 Script Used to Generate This Report

The following Python script utilizes GitHub's REST API to collect PR and commit data. This ensures accuracy and verifiability of the above contribution summary.

<details>
<summary>📜 Click to view full script</summary>

```python
import requests
import datetime
from collections import defaultdict
import warnings
from urllib3.exceptions import NotOpenSSLWarning

warnings.filterwarnings("ignore", category=NotOpenSSLWarning)

# === CONFIGURATION ===
ORG = "UofL-CSE-350-Team13"
REPO = "MedicationManager"
BRANCH = "main"
TOKEN = "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"
HEADERS = {"Authorization": f"Bearer {TOKEN}"}

since_date = (datetime.datetime.utcnow() - datetime.timedelta(days=120)).isoformat() + "Z"

TEAM_MEMBER_ALIASES = {
    "Melissa Gandy": ["melissa gandy", "melissagandy"],
    "Jonah Buckley": ["jonah buckley", "jonahbuckley"],
    "Jeremie Bashala": ["jeremie bashala", "jeremiebashala"],
    "Daniel Kelly": ["daniel kelly", "danielkelly"],
    "Eric Bush": ["eric bush", "eric.bush"]
}

def get_merged_prs():
    print(f"🔍 Fetching PRs merged into '{BRANCH}' since {since_date}...")
    prs = []
    page = 1
    while True:
        url = f"https://api.github.com/repos/{ORG}/{REPO}/pulls"
        params = {
            "state": "closed",
            "base": BRANCH,
            "sort": "updated",
            "direction": "desc",
            "per_page": 100,
            "page": page
        }
        resp = requests.get(url, headers=HEADERS, params=params)
        data = resp.json()
        if not data or "message" in data:
            break
        for pr in data:
            if pr.get("merged_at") and pr["merged_at"] >= since_date:
                prs.append(pr)
        page += 1
    return prs

def get_pr_commits(pr_number):
    url = f"https://api.github.com/repos/{ORG}/{REPO}/pulls/{pr_number}/commits"
    resp = requests.get(url, headers=HEADERS)
    return resp.json()

def get_direct_main_commits():
    print(f"🔍 Fetching direct commits to '{BRANCH}' since {since_date}...")
    commits = []
    page = 1
    while True:
        url = f"https://api.github.com/repos/{ORG}/{REPO}/commits"
        params = {
            "sha": BRANCH,
            "since": since_date,
            "per_page": 100,
            "page": page
        }
        resp = requests.get(url, headers=HEADERS, params=params)
        data = resp.json()
        if not data or "message" in data:
            break
        commits.extend(data)
        page += 1
    return commits

def summarize_contributions(prs, direct_commits):
    author_commits = defaultdict(list)

    for pr in prs:
        commits = get_pr_commits(pr['number'])
        for c in commits:
            name = c['commit']['author']['name']
            date = c['commit']['author']['date']
            author_commits[name].append(date)

    for c in direct_commits:
        name = c['commit']['author']['name']
        date = c['commit']['author']['date']
        author_commits[name].append(date)

    print(f"\n📊 Contribution Summary (PRs + direct commits to '{BRANCH}'):\n")

    all_authors_normalized = {name.lower().replace(" ", ""): name for name in author_commits.keys()}

    for member, aliases in TEAM_MEMBER_ALIASES.items():
        matched_dates = []
        for alias in aliases:
            key = alias.lower().replace(" ", "")
            if key in all_authors_normalized:
                actual_name = all_authors_normalized[key]
                matched_dates.extend(author_commits[actual_name])

        if matched_dates:
            matched_dates.sort()
            print(f"{member} - {len(matched_dates)} commits, first: {matched_dates[0][:10]}, last: {matched_dates[-1][:10]}")
        else:
            print(f"{member} - no data")

def main():
    prs = get_merged_prs()
    direct_commits = get_direct_main_commits()
    summarize_contributions(prs, direct_commits)

if __name__ == "__main__":
    main()
```

</details>

---

> 📌 **Note**: This report is intentionally scoped only to **codebase contributions**, as they directly determine the progress and success of the software development aspect of the project.
