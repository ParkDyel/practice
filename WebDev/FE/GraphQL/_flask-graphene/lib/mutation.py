import graphene
class setDefaultMutation(graphene.Mutation):
    class Arguments:
        name = graphene.String()

    # 반환값
    message = graphene.String()

    # 리솔버
    @staticmethod
    def mutate(root, info, name):
        return "Success"

class Mutation(graphene.ObjectType):
    set_default = setDefaultMutation.Field()