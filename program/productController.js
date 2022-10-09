const Product = require("../Models/productModel")
const jwt = require("jsonwebtoken");
const catchAsyncErrors = require("../Middleware/catchAsyncErrors");
const ErrorHandler = require("../Utils/errorHandler");

exports.product = async (req, res) => {
    try {

        const product = await Product.create({
            Image: req.body.Image,
            Name: req.body.Name,
            Company: req.body.Company,
            Category: req.body.Category,
            Features: req.body.Features,
            Currency: req.body.Currency,
            Price: req.body.Price,
            Quantity: req.body.Quantity,
            Rating: req.body.Rating,
            Review: req.body.Review,
            SellerId: req.user._id //req.user will give all details from mongodb
            // SellerID: jwt.verify(req.cookies.token , process.env.JWT_SECRET_KEY).id
        })
        console.log(product);
        res.status(200).json({  //status=200 means ok
            success: true, //used for error handling
            product  //sends mongo db details to postman(client)
        })
    }
    catch (e) {
        console.log(e)
        // res.send(e);
    }
}

exports.getProductDetails = catchAsyncErrors(async (req, res, next) => {
    const product = await Product.findById(req.params._id).populate("SellerId"); //populate is used connect and get details from another table
    //(which id to update taken from params)
    if(!product){
        return next(new ErrorHandler("Product not Found",404))
    }
    res.json({
        success: true,
        product
    });
})




exports.getAllProducts = async (req, res) => {
    try {

        const { keyword, price } = req.query
        const resultPerPage = 3
        const page = req.query.page ? req.query.page : 1
        console.log(!!keyword)

        let priceInString = JSON.stringify(price) // object to string so that we can change its property
        priceInString = priceInString.replace(/\b(gt|gte|lt|lte)\b/g, (key) => `$${key}`) //regex f'n to place $ , /g-global
        let priceInObject = JSON.parse(priceInString) // string to object

        // console.log(priceInString)
        // console.log(priceInObject)

        let filter = []
        // filter.push("hi!!")
        keyword &&
            filter.push({
                $or:
                    [{ Name: { $regex: keyword, $options: "i" } },
                    { Company: { $regex: keyword, $options: "i" } }
                    ]
            })

        price &&
            filter.push({
                "Price": priceInObject
            })


        // console.log(filter)

        const product = await Product.find(
            filter.length ? {
                $and: filter
            } : {}).skip(resultPerPage * (page - 1)).limit(resultPerPage)

        // // const product =await Product.find({"Name":req.body.Name}); //using body
        // //const product =await Product.find({"Name":req.query.Name}); //using query (used for giving variable data , not shown to user)
        // const { page, keyword, price } = req.query

        res.status(200).json({ product })

    }
    catch (e) {
        console.log(e)
    }
}

